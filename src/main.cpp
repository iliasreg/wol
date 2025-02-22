#include "../socket/socket.hpp"
#include "../wol/wol.hpp"

#include <iostream>

int main(int argc, char **argv){
    if(argc != 2){
        std::cerr << "Usage: " << argv[0] << " [MAC_ADDRESS]" << std::endl;
        return 1;
    }

    try{
        auto mac = parse_mac(argv[1]);
        auto m_packet = magic_packet(mac);
        send_packet(m_packet);
        std::cout << "magic packet sent successfully!" << std::endl;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}