//
// Created by donsimon on 1/30/25.
//
#include <iostream>
#include<unordered_map>
#include <mutex>
#include<boost/asio.hpp>

class KeyValueStore {
private:
    //static std::mutex mutex_;
    static std::unordered_map<std::string,std::string> storage;
public:
    static void set(std::string key,std::string value) {
        //std::lock_guard<std::mutex> lock(mutex_);
        storage.emplace(std::pair<std::string,std::string>{key,value});
    }
    static auto get(std::string key) {
        //std::lock_guard<std::mutex> lock(mutex_);
        return *storage.find(key);
    }


};

class Session :std::enable_shared_from_this<Session>{
private:
    boost::asio::ip::tcp::socket socket_;
    boost::asio::streambuf buffer_;
public:
    Session(boost::asio::ip::tcp::socket socket):socket_(std::move(socket)) {
    }
    void do_read() {
        auto self=shared_from_this();
        boost::asio::async_read_until(socket_,buffer_,'\n',[this,self](boost::system::error_code error_code,size_t lenght) {
            std::istream is(&buffer_);
            std::string command;
            is >> command;

            if(command=="SET") {
                std::string key,value;
                is>>key>>value;
                KeyValueStore::set(key,value);
                do_write("OK");
            }else if(command=="GET") {
                std::string key;
                is>>key;
                do_write(KeyValueStore::get(key).second);
            }
            else {
                do_write("ERROR");
            }
        });
    }
    void do_write(std::string massage) {
        auto self=shared_from_this();
        boost::asio::async_write(socket_,boost::asio::buffer(massage),[this,self](boost::system::error_code error_code,size_t) {
            if(!error_code) {
                do_read();
            }
        });
    }
};
class Server {
private:
    boost::asio::ip::tcp::acceptor acceptor_;

    void do_accpet() {
        acceptor_.async_accept([this](boost::system::error_code error_code,boost::asio::ip::tcp::socket socket) {
           if(!error_code) {
               std::make_shared<Session>(std::move(socket))->do_read();
           }
        });
    }
public:
    Server(boost::asio::io_context &io,short port):acceptor_(io,boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(),port)){}
};
int main(int argc, char* argv[]) {
    try
    {
        if (argc != 2)
        {
            std::cerr << "Usage: async_tcp_echo_server <port>\n";
            return 1;
        }

        boost::asio::io_context io_context;

        Server s(io_context, std::atoi(argv[1]));

        io_context.run();
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return 0;
}