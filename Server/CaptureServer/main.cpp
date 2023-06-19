#include <iostream>
#include <framebuffer.h>
#include <exception>
#include <ostream>
using namespace std;

int main()
{
    cout << "Starting the server"<< endl;
    try {
         FrameBuffer buf("/dev/fb0");
         std::cout<<buf.height()<<"X"<<buf.width()<<"    "<<buf.colorDepth()<<"  line: "<<buf.linelength()<<endl;
         auto b = buf.readFB();
         char arr[b.size()];
         std::copy(b.begin(), b.end(), arr);


         std::ofstream file("myfile.raw", std::ios::binary);
         file.write(arr, b.size());

    }  catch (exception &e) {

        std::cout<<"  Exception: "<<e.what()<<endl;
    }
    catch (string &e) {

           std::cout<<"  Exception: "<<e<<endl;
    }

    return 0;
}
