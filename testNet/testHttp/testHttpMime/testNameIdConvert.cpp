#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderContentType.hpp"
#include "TestLog.hpp"

using namespace obotcha;

struct NameMap {
public:
  int id;
  const char *name;
};

#define MEMBER(X) \
{ static_cast<int>(st(HttpMime)::Type::X),st(HttpMime)::X->toChars()}


NameMap names[1024] = {
    MEMBER(TextHtml),
    MEMBER(TextCss),
    MEMBER(TextXml),
    MEMBER(ImageGif),
    MEMBER(ImageJpeg),
    MEMBER(ApplicationJs),
    MEMBER(ApplicationAtomXml),
    MEMBER(ApplicationRss),
    MEMBER(TextMathml),
    MEMBER(TextPlain),
    MEMBER(TextVndSunJ2meAppDes),
    MEMBER(TextVndWapWml),
    MEMBER(TextXComponent),
    MEMBER(ImagePng),
    MEMBER(ImageSvgXml),
    MEMBER(ImageTiff),
    MEMBER(ImageVndWapWbmp),
    MEMBER(ImageWebp),
    MEMBER(ImageXIcon),
    MEMBER(ImageXJng),
    MEMBER(ImageXMsBmp),
    MEMBER(ApplicationFontWoff),
    MEMBER(ApplicationJavaArchive),
    MEMBER(ApplicationJson),
    MEMBER(ApplicationMaxBinhex40),
    MEMBER(ApplicationMsword),
    MEMBER(ApplicationPdf),
    MEMBER(ApplicationPostScript),
    MEMBER(ApplicationRtf),
    MEMBER(ApplicationVndAppleMpegurl),
    MEMBER(ApplicationVndGoogleEarthKmlXml),
    MEMBER(ApplicationVndGoogleEarthKmz),
    MEMBER(ApplicationVndMsExcel),
    MEMBER(ApplicationVndMsFontObject),
    MEMBER(ApplicationVndMsPpt),
    MEMBER(ApplicationVndOasisOpendocGraphics),
    MEMBER(ApplicationVndOasisOpendocPresentation),
    MEMBER(ApplicationVndOasisOpendocSpreadsheet),
    MEMBER(ApplicationVndOasisOpendocText),
    MEMBER(ApplicationVndOpenxmlPresentation),
    MEMBER(ApplicationVndOpenXmlSheet),
    MEMBER(ApplicationVndOepnXmlDoc),
    MEMBER(ApplicationVndWapWmls),
    MEMBER(Application7z),
    MEMBER(ApplicationXCocoa),
    MEMBER(ApplicationXJavaArch),
    MEMBER(ApplicationXJavaJnlpFile),
    MEMBER(ApplicationXMakeself),
    MEMBER(ApplicationXPerl),
    MEMBER(ApplicationXPilot),
    MEMBER(ApplicationXRarCompressed),
    MEMBER(ApplicationXReadhatPkgManager),
    MEMBER(ApplicationXSea),
    MEMBER(ApplicationXShockwaveFlash),
    MEMBER(ApplicationXStuffit),
    MEMBER(ApplicationXTcl),
    MEMBER(ApplicationXX509CaCert),
    MEMBER(ApplicationXXpinstall),
    MEMBER(ApplicationXhtmlXml),
    MEMBER(ApplicationXspfXml),
    MEMBER(ApplicationZip),
    MEMBER(ApplicationOctetStream),
    MEMBER(AudioMidi),
    MEMBER(AudioMpeg),
    MEMBER(AudioOgg),
    MEMBER(AudioXM4a),
    MEMBER(AudioXRealAudio),
    MEMBER(Video3Gpp),
    MEMBER(VideoMp2t),
    MEMBER(VideoMp4),
    MEMBER(VideoMpeg),
    MEMBER(VidoQuicktime),
    MEMBER(VideoWebm),
    MEMBER(VideoXflv),
    MEMBER(VideoXM4v),
    MEMBER(VideoXMng),
    MEMBER(VideoXMsAsf),
    MEMBER(VideoXMsWmv),
    MEMBER(VideoXMsVideo),
    MEMBER(MultiPartFormData),
    MEMBER(XFormUrlEncoded),
};


void testNameIdConvert() {
  //for(int i = st(HttpMime)::TypeTextHtml;i <st(HttpMime)::TypeMax;i++ ) {
  //for(auto i = st(HttpMime)::Type.begin(); i != st(HttpMime)::Type.end();i++) {
  for(auto i = (std::underlying_type<st(HttpMime)::Type>::type)st(HttpMime)::Type::TextHtml;
          i <= (std::underlying_type<st(HttpMime)::Type>::type)st(HttpMime)::Type::XFormUrlEncoded;
          i++) {
	 
	  HttpMime mime = HttpMime::New();
      mime->setTypeId(static_cast<st(HttpMime)::Type>(i));
      String f1 = mime->getType();
      if(!f1->sameAs(names[i].name)) {
        TEST_FAIL("[TestHttpMime name to id case1]");
      }

      if(mime->getTypeId() != static_cast<st(HttpMime)::Type>(i)) {
        TEST_FAIL("[TestHttpMime name to id case2] ,i is %d,id is %d",
					static_cast<int>(i),
					static_cast<int>(mime->getTypeId()));
      }
  }
  
  for(auto i = (std::underlying_type<st(HttpMime)::Type>::type)st(HttpMime)::Type::TextHtml;
          i <= (std::underlying_type<st(HttpMime)::Type>::type)st(HttpMime)::Type::XFormUrlEncoded;
          i++) {
      HttpMime mime = HttpMime::New();//st(HttpMime)::createById(i);
      mime->setType(names[i].name);
      
      if(mime->getTypeId() != static_cast<st(HttpMime)::Type>(i)) {
          TEST_FAIL("[TestHttpMime name to id case3] ,i is %d,id is %d",static_cast<int>(i),static_cast<int>(mime->getTypeId()));
      }
      
      if(!mime->getType()->sameAs(names[i].name)) {
          TEST_FAIL("[TestHttpMime name to id case4] ,i is %d,id is %d",static_cast<int>(i),static_cast<int>(mime->getTypeId()));
      }
  }

  TEST_OK("[TestHttpMime name to id case100]");

}
