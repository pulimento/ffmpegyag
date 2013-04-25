#ifndef VIDEOFRAME_H
#define VIDEOFRAME_H

#include <GL/gl.h>
#include <wx/dynarray.h>

#include "Libav.h"

class VideoFrame
{
    public: VideoFrame();
    // the pointer FrameData will be freed by this destructor, make sure not freeing it's content externally!
    public: VideoFrame(int64_t FrameTimestamp, int64_t FrameTimecode, int64_t FrameDuration, int FrameWidth, int FrameHeight, PixelFormat FrameFormat, AVPictureType FrameType);
    public: VideoFrame(int64_t FrameTimestamp, int64_t FrameTimecode, int64_t FrameDuration, int FrameWidth, int FrameHeight, AVPictureType FrameType, unsigned char Red, unsigned char Green, unsigned char Blue);
    public: virtual ~VideoFrame();

    public: int64_t Timestamp;
    public: int64_t Timecode; // in milliseconds
    public: int64_t Duration; // in milliseconds
    public: int Width;
    public: int Height;
    public: PixelFormat AVFormat;
    public: AVPictureType AVType;
    public: size_t DataSize;
    public: unsigned char* Data;

    public: void FillFrame(unsigned char* FrameData);
    public: GLint GetGLFormat();
    public: wxString GetPicType();
};

WX_DEFINE_ARRAY(VideoFrame*, VideoFrameArray);

#endif // VIDEOFRAME_H
