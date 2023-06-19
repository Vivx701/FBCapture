#include "framebuffer.h"

FrameBuffer::FrameBuffer(std::string device): m_fbDevice(device)
{
    if (access(device.c_str(), F_OK) != 0)
    {
        throw FBDEV_NOT_FOUND;
    }
    fetchFBDetails();
}

void FrameBuffer::fetchFBDetails()
{
    int fd = open(m_fbDevice.c_str(), O_RDONLY);
    if(fd == -1)
    {
        close(fd);
        throw FBDEV_NOT_FOUND+" "+m_fbDevice;
    }
    struct fb_var_screeninfo fb_varinfo;
    if(ioctl(fd, FBIOGET_VSCREENINFO, &fb_varinfo) < 0)
    {
         close(fd);
         throw FAILED_FETCH_VSCREENINFO;
    }
    struct fb_fix_screeninfo fb_fixedinfo;
    if(ioctl(fd, FBIOGET_FSCREENINFO, &fb_fixedinfo) < 0)
    {
        close(fd);
        throw FAILED_FETCH_FSCREENINFO;
    }

    m_width       = fb_varinfo.xres;
    m_height      = fb_varinfo.yres;
    m_colorDepth  = fb_varinfo.bits_per_pixel;
    m_linelength  = fb_fixedinfo.line_length;
    m_isGrayScale = (fb_varinfo.grayscale != 0);


}

bool FrameBuffer::isGrayScale() const
{
    return m_isGrayScale;
}

std::vector<unsigned char> FrameBuffer::readFB()
{
    std::ifstream fbdev(m_fbDevice, std::ios::binary);
    std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(fbdev), {});
    return buffer;
}

int FrameBuffer::linelength() const
{
    return m_linelength;
}

int FrameBuffer::colorDepth() const
{
    return m_colorDepth;
}

int FrameBuffer::height() const
{
    return m_height;
}

int FrameBuffer::width() const
{
    return m_width;
}
