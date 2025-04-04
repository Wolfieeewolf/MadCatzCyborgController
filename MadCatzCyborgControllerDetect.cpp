/*---------------------------------------------------------*\
| MadCatz Cyborg Gaming Light Controller detector for OpenRGB |
|                                                              |
\*---------------------------------------------------------*/

#include "Detector.h"
#include "MadCatzCyborgController.h"
#include "RGBController.h"
#include "RGBController_MadCatzCyborg.h"
#include "ResourceManager.h"
#include <hidapi.h>

// From pycyborg: VENDOR=0x06a3, PRODUCT=0x0dc5
#define MADCATZ_VID        0x06A3
#define MADCATZ_CYBORG_PID 0x0DC5

/******************************************************************************************\
*                                                                                          *
*   DetectMadCatzCyborgControllers                                                         *
*                                                                                          *
*       Tests the USB address to find MadCatz Cyborg Gaming Light devices                  *
*                                                                                          *
\******************************************************************************************/

void DetectMadCatzCyborgControllers(hid_device_info* info, const std::string& name)
{
    hid_device* dev = hid_open_path(info->path);
    
    if(dev)
    {
        MadCatzCyborgController* controller = new MadCatzCyborgController(dev, info->path);
        controller->Initialize();
        
        RGBController_MadCatzCyborg* rgb_controller = new RGBController_MadCatzCyborg(controller);
        rgb_controller->name = name;
        
        ResourceManager::get()->RegisterRGBController(rgb_controller);
    }
}

REGISTER_HID_DETECTOR("MadCatz Cyborg Gaming Light", DetectMadCatzCyborgControllers, MADCATZ_VID, MADCATZ_CYBORG_PID);
