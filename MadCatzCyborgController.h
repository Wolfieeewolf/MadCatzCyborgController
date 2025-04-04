/*---------------------------------------------------------*\
| MadCatz Cyborg Gaming Light Controller driver for OpenRGB    |
|                                                              |
\*---------------------------------------------------------*/

#pragma once

#include <string>
#include <hidapi.h>

class MadCatzCyborgController
{
public:
    MadCatzCyborgController(hid_device* dev_handle, const char* path);
    ~MadCatzCyborgController();

    std::string     GetDeviceLocation();
    std::string     GetSerialString();

    void            Initialize();
    void            SetLEDColor(unsigned char red, unsigned char green, unsigned char blue);
    void            SetIntensity(unsigned char intensity);
    void            SetPosition(unsigned char position_byte1, unsigned char position_byte2);
    void            SetVerticalPosition(unsigned char v_pos);

private:
    hid_device*     dev;
    std::string     location;
    
    void            UsbIdleRequest();
    void            UsbResetRequest();
    void            UsbGetReport();
    
    // Protocol constants
    static const unsigned char CMD_ENABLE    = 0xA1;
    static const unsigned char CMD_COLOR     = 0xA2;
    static const unsigned char CMD_POSITION  = 0xA4;
    static const unsigned char CMD_V_POS     = 0xA5;
    static const unsigned char CMD_INTENSITY = 0xA6;
    static const unsigned char CMD_RESET     = 0xA7;
    
    // Position constants
    struct Position
    {
        static const unsigned char CENTER[2];
        static const unsigned char N[2];
        static const unsigned char NE[2];
        static const unsigned char E[2]; 
        static const unsigned char SE[2];
        static const unsigned char S[2];
        static const unsigned char SW[2];
        static const unsigned char W[2];
        static const unsigned char NW[2];
    };
    
    // Vertical position constants
    struct VerticalPosition
    {
        static const unsigned char ANY    = 0x00;
        static const unsigned char LOW    = 0x08;
        static const unsigned char MIDDLE = 0x04;
        static const unsigned char HIGH   = 0x02;
    };
};
