#include <iostream>
#include <framebuffer.h>
#include <exception>

using namespace std;

int main()
{
    cout << "Starting the server"<< endl;
    try {
         FrameBuffer buf("/dev/fb0");
         std::cout<<buf.height()<<"X"<<buf.width()<<"    "<<buf.colorDepth()<<"  line: "<<buf.linelength()<<endl;

    }  catch (exception &e) {

        std::cout<<"  Exception: "<<e.what()<<endl;
    }
    catch (string &e) {

           std::cout<<"  Exception: "<<e<<endl;
    }

    return 0;
}
