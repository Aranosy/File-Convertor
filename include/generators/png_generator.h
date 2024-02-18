#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <crc32.h>

using namespace std;

namespace png
{
    // TODO: Generate function
    // TODO: Dencrypt_pixels function
    
    template <typename T, typename R>
    void ValueToHex (T str, R& ret)
    {
        std::stringstream stream;
        stream << std::hex << str;
        stream >> ret;
    }

    string CreateChuck(string chunkType, string chunkData)
    {

        //  Get Length of chunkData in hex
        string length;
        string res;
        ValueToHex(chunkData.size() / 2, res);

        for (short i = 0; i < 8 - res.size(); i++)
            length += '0';
        length += res;

        // Get CRC-32 of chunkType and chunkData
        vector<unsigned char> crcInput; // Data for crc algorithm
        string dataCRC = chunkType + chunkData;
        for (unsigned int i = 0; i < dataCRC.length(); i+= 2)
        {
            string hexStr = {dataCRC[i], dataCRC[i+1]}; // Get a single string hex value
            int t;
            ValueToHex(hexStr, t); // Convert string hex to number
            crcInput.push_back(static_cast<unsigned char>(t));
        }

        unsigned long crcN = utils::crc(crcInput.data(), crcInput.size());
        string crc = "";
        string T = "";
        ValueToHex(crcN, T);
        for (short i = 0; i < 8 - T.size(); i++)
            crc += '0';
        crc += T;

        return length + chunkType + chunkData + crc;
    }



}