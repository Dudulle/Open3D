/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** rtspvideocapturer.cpp
**
** -------------------------------------------------------------------------*/

#ifdef HAVE_LIVE555

#include "open3d/visualization/webrtc_server/RTSPVideoCapturer.h"

#include <rtc_base/logging.h>

namespace open3d {
namespace visualization {
namespace webrtc_server {

RTSPVideoCapturer::RTSPVideoCapturer(
        const std::string& uri, const std::map<std::string, std::string>& opts)
    : LiveVideoSource(uri, opts, false) {
    RTC_LOG(INFO) << "RTSPVideoCapturer " << uri;
}

RTSPVideoCapturer::~RTSPVideoCapturer() {}

void RTSPVideoCapturer::onError(RTSPConnection& connection, const char* error) {
    RTC_LOG(LS_ERROR) << "RTSPVideoCapturer:onError url:"
                      << m_liveclient.getUrl() << " error:" << error;
    connection.start(1);
}

}  // namespace webrtc_server
}  // namespace visualization
}  // namespace open3d
#endif