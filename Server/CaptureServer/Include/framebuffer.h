#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

//SYSTEM HEADERS
#include <unistd.h>
#include <linux/fb.h>
#include <fcntl.h>
#include <sys/ioctl.h>

//C++ HEADER
#include <string>



//EXCEPTIONS
const std::string FBDEV_NOT_FOUND = "Failed to open fbDev file";
const std::string FAILED_FETCH_VSCREENINFO = "Failed fetch VSCREENINFO";
const std::string FAILED_FETCH_FSCREENINFO = "Failed fetch FSCREENINFO";

class FrameBuffer
{
public:
    FrameBuffer(std::string device);

    int width() const;

    int height() const;

    int colorDepth() const;

    int linelength() const;

    bool isGrayScale() const;

private:
    void fetchFBDetails();
    std::string m_fbDevice;
    int m_width;
    int m_height;
    int m_colorDepth;
    int m_linelength;
    bool m_isGrayScale;
};

#endif // FRAMEBUFFER_H
