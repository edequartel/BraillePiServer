#include <iostream>
#include "audiocentre.h"    //class audiocentre layer over playaudio

using namespace std;

audiocentre ac;

int main()
{
    int res=0;
    while (1)
    {
        cout << "========================BraillePiServer=====================" << endl;
        ac.playfile("/home/pi/Documents/sound/general/basic/fullvolume/Complete_3.mp3");
        int res=system("/home/pi/Documents/programs/BraillePiFramework/bin/Debug/./BraillePi");
        res=res/256;
        cout << "braillepiclient output " << res <<endl;
        if (res==11)
        {
            ac.playfile("/home/pi/Documents/sound/general/basic/fullvolume/Notification_8.mp3");
            int result=system("/home/pi/Documents/programs/setkeys/bin/Debug/./setkeys");
            ac.playfile("/home/pi/Documents/sound/general/basic/fullvolume/Notification_8.mp3");
            system("reboot");
        };
    }
    return 0;
}
