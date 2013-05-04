#include "WXGLDevice.h"

WXGLDevice::WXGLDevice()
{
    widget = NULL;
}

WXGLDevice::~WXGLDevice()
{
    //
}

void* WXGLDevice::CreateWidget(const char* title, int width, int height, bool fullscreen)
{
    // TODO: create wxWidgets window
    return NULL;
}

void WXGLDevice::DestroyWidget(void* Widget)
{
    Release();
    wxWindow* tmp = (wxWindow*)Widget;
    if(tmp)
    {
        if(tmp == widget)
        {
            // internal widget is same as widget requested for destruction
            widget = NULL;
        }
        wxDELETE(tmp);
        tmp = NULL;
        //Widget = NULL; // statement has no effect, pointer only valid in local scope
    }
}

bool WXGLDevice::Init(void* Widget)
{
    widget = (wxGLCanvas*)Widget;
    if(widget && widget->GetContext())
    {
        return true;
    }
    return false;
}

void WXGLDevice::Release()
{
    //
}

void WXGLDevice::MakeCurrent()
{
    widget->SetCurrent();
}

void WXGLDevice::SwapBuffers()
{
    // FIXME: only swap when doublebuffering is enabled!
    // has SwapBuffer any negative effect on singlebuffering anyway?
    // create benchmark
    #ifdef __WINDOWS__
    widget->SwapBuffers();
    #endif
    GLDevice::SwapBuffers();
}
