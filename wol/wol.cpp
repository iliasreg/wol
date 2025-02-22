#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <sstream>
#include <cstdint>

#include "wol.hpp"

std::vector<uint8_t> parse_mac(const std::string& address){
    std::vector<uint8_t> mac_bytes;
    std::stringstream ss(address);
    std::string byte_str;

    for (uint8_t i = 0; i < 6; i++){
        if(!std::getline(ss, byte_str, ':')){
            throw std::invalid_argument("Invalid MAC address format");
        }
        mac_bytes.push_back(static_cast<uint8_t>(std::stoul(byte_str, nullptr, 16)));
    }
    return mac_bytes;
}

std::vector<uint8_t> magic_packet(std::vector<uint8_t>& packet){
    std::vector<uint8_t> m_packet;
    m_packet.insert(m_packet.end(), 6, 0xFF); // Preambule of 6 0xFF -> 6 bytes
    for (uint16_t i = 0; i < 16; i++){
        m_packet.insert(m_packet.end(), packet.begin(), packet.end()); // 16 repititions of 6 byte MAC address 
    }
    return m_packet; // TotalSize = 6 + 6*16 = 102bytes
}