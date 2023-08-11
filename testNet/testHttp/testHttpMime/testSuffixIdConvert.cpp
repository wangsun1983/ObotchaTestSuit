#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderContentType.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void check(String suffix,st(HttpMime)::Type expectedId) {
  //HttpMime mime = st(HttpMime)::createBySuffix(suffix);
  HttpMime mime = createHttpMime();
  mime->setSuffix(suffix);
  //mime->setSuffix(suffix);
  if(mime->getTypeId() != expectedId) {
    TEST_FAIL("[TestHttpMime suffix to id case1],id is %d,expectedId is %d,suffix is %s",
				static_cast<int>(mime->getTypeId()),
				static_cast<int>(expectedId),
				suffix->toChars());
  }
}

void testSuffixIdConvert() {
  check(st(HttpMime)::SuffixHtml,st(HttpMime)::Type::TextHtml);
  check(st(HttpMime)::SuffixHtm,st(HttpMime)::Type::TextHtml);
  check(st(HttpMime)::SuffixShtml,st(HttpMime)::Type::TextHtml);

  check(st(HttpMime)::SuffixCss,st(HttpMime)::Type::TextCss);

  check(st(HttpMime)::SuffixXml,st(HttpMime)::Type::TextXml);

  check(st(HttpMime)::SuffixGif,st(HttpMime)::Type::ImageGif);

  check(st(HttpMime)::SuffixJpeg,st(HttpMime)::Type::ImageJpeg);
  check(st(HttpMime)::SuffixJpg,st(HttpMime)::Type::ImageJpeg);

  check(st(HttpMime)::SuffixJs,st(HttpMime)::Type::ApplicationJs);

  check(st(HttpMime)::SuffixAtom,st(HttpMime)::Type::ApplicationAtomXml);

  check(st(HttpMime)::SuffixRss,st(HttpMime)::Type::ApplicationRss);

  check(st(HttpMime)::SuffixMml,st(HttpMime)::Type::TextMathml);

  check(st(HttpMime)::SuffixTxt,st(HttpMime)::Type::TextPlain);

  check(st(HttpMime)::SuffixJad,st(HttpMime)::Type::TextVndSunJ2meAppDes);

  check(st(HttpMime)::SuffixWml,st(HttpMime)::Type::TextVndWapWml);

  check(st(HttpMime)::SuffixHtc,st(HttpMime)::Type::TextXComponent);

  check(st(HttpMime)::SuffixPng,st(HttpMime)::Type::ImagePng);

  check(st(HttpMime)::SuffixSvg,st(HttpMime)::Type::ImageSvgXml);
  check(st(HttpMime)::SuffixSvgz,st(HttpMime)::Type::ImageSvgXml);

  check(st(HttpMime)::SuffixTif,st(HttpMime)::Type::ImageTiff);
  check(st(HttpMime)::SuffixTiff,st(HttpMime)::Type::ImageTiff);

  check(st(HttpMime)::SuffixWbmp,st(HttpMime)::Type::ImageVndWapWbmp);

  check(st(HttpMime)::SuffixWebp,st(HttpMime)::Type::ImageWebp);

  check(st(HttpMime)::SuffixIco,st(HttpMime)::Type::ImageXIcon);

  check(st(HttpMime)::SuffixJng,st(HttpMime)::Type::ImageXJng);

  check(st(HttpMime)::SuffixBmp,st(HttpMime)::Type::ImageXMsBmp);

  check(st(HttpMime)::SuffixWoff,st(HttpMime)::Type::ApplicationFontWoff);

  check(st(HttpMime)::SuffixJar,st(HttpMime)::Type::ApplicationJavaArchive);
  check(st(HttpMime)::SuffixWar,st(HttpMime)::Type::ApplicationJavaArchive);
  check(st(HttpMime)::SuffixEar,st(HttpMime)::Type::ApplicationJavaArchive);

  check(st(HttpMime)::SuffixJson,st(HttpMime)::Type::ApplicationJson);

  check(st(HttpMime)::SuffixHqx,st(HttpMime)::Type::ApplicationMaxBinhex40);

  check(st(HttpMime)::SuffixDoc,st(HttpMime)::Type::ApplicationMsword);

  check(st(HttpMime)::SuffixPdf,st(HttpMime)::Type::ApplicationPdf);

  check(st(HttpMime)::SuffixPs,st(HttpMime)::Type::ApplicationPostScript);
  check(st(HttpMime)::SuffixEps,st(HttpMime)::Type::ApplicationPostScript);
  check(st(HttpMime)::SuffixAi,st(HttpMime)::Type::ApplicationPostScript);

  check(st(HttpMime)::SuffixRtf,st(HttpMime)::Type::ApplicationRtf);

  check(st(HttpMime)::SuffixM3u8,st(HttpMime)::Type::ApplicationVndAppleMpegurl);

  check(st(HttpMime)::SuffixKml,st(HttpMime)::Type::ApplicationVndGoogleEarthKmlXml);

  check(st(HttpMime)::SuffixKmz,st(HttpMime)::Type::ApplicationVndGoogleEarthKmz);

  check(st(HttpMime)::SuffixXls,st(HttpMime)::Type::ApplicationVndMsExcel);

  check(st(HttpMime)::SuffixEot,st(HttpMime)::Type::ApplicationVndMsFontObject);

  check(st(HttpMime)::SuffixPpt,st(HttpMime)::Type::ApplicationVndMsPpt);

  check(st(HttpMime)::SuffixOdj,st(HttpMime)::Type::ApplicationVndOasisOpendocGraphics);

  check(st(HttpMime)::SuffixOdp,st(HttpMime)::Type::ApplicationVndOasisOpendocPresentation);

  check(st(HttpMime)::SuffixOds,st(HttpMime)::Type::ApplicationVndOasisOpendocSpreadsheet);

  check(st(HttpMime)::SuffixOdt,st(HttpMime)::Type::ApplicationVndOasisOpendocText);

  check(st(HttpMime)::SuffixPptx,st(HttpMime)::Type::ApplicationVndOpenxmlPresentation);

  check(st(HttpMime)::SuffixXlsx,st(HttpMime)::Type::ApplicationVndOpenXmlSheet);

  check(st(HttpMime)::SuffixDocx,st(HttpMime)::Type::ApplicationVndOepnXmlDoc);

  check(st(HttpMime)::SuffixWmlc,st(HttpMime)::Type::ApplicationVndWapWmls);

  check(st(HttpMime)::Suffix7z,st(HttpMime)::Type::Application7z);

  check(st(HttpMime)::SuffixCco,st(HttpMime)::Type::ApplicationXCocoa);

  check(st(HttpMime)::SuffixJardiff,st(HttpMime)::Type::ApplicationXJavaArch);

  check(st(HttpMime)::SuffixJnlp,st(HttpMime)::Type::ApplicationXJavaJnlpFile);

  check(st(HttpMime)::SuffixRun,st(HttpMime)::Type::ApplicationXMakeself);

  check(st(HttpMime)::SuffixPl,st(HttpMime)::Type::ApplicationXPerl);
  check(st(HttpMime)::SuffixPm,st(HttpMime)::Type::ApplicationXPerl);

  check(st(HttpMime)::SuffixPrc,st(HttpMime)::Type::ApplicationXPilot);
  check(st(HttpMime)::SuffixPdb,st(HttpMime)::Type::ApplicationXPilot);

  check(st(HttpMime)::SuffixRar,st(HttpMime)::Type::ApplicationXRarCompressed);

  check(st(HttpMime)::SuffixRpm,st(HttpMime)::Type::ApplicationXReadhatPkgManager);

  check(st(HttpMime)::SuffixSea,st(HttpMime)::Type::ApplicationXSea);

  check(st(HttpMime)::SuffixSwf,st(HttpMime)::Type::ApplicationXShockwaveFlash);

  check(st(HttpMime)::SuffixSit,st(HttpMime)::Type::ApplicationXStuffit);

  check(st(HttpMime)::SuffixTcl,st(HttpMime)::Type::ApplicationXTcl);
  check(st(HttpMime)::SuffixTk,st(HttpMime)::Type::ApplicationXTcl);

  check(st(HttpMime)::SuffixDer,st(HttpMime)::Type::ApplicationXX509CaCert);
  check(st(HttpMime)::SuffixPem,st(HttpMime)::Type::ApplicationXX509CaCert);
  check(st(HttpMime)::SuffixCrt,st(HttpMime)::Type::ApplicationXX509CaCert);

  check(st(HttpMime)::SuffixXpi,st(HttpMime)::Type::ApplicationXXpinstall);

  check(st(HttpMime)::SuffixXhtml,st(HttpMime)::Type::ApplicationXhtmlXml);

  check(st(HttpMime)::SuffixXspf,st(HttpMime)::Type::ApplicationXspfXml);

  check(st(HttpMime)::SuffixZip,st(HttpMime)::Type::ApplicationZip);

  check(st(HttpMime)::SuffixBin,st(HttpMime)::Type::ApplicationOctetStream);
  check(st(HttpMime)::SuffixExe,st(HttpMime)::Type::ApplicationOctetStream);
  check(st(HttpMime)::SuffixDll,st(HttpMime)::Type::ApplicationOctetStream);
  check(st(HttpMime)::SuffixDeb,st(HttpMime)::Type::ApplicationOctetStream);
  check(st(HttpMime)::SuffixDmg,st(HttpMime)::Type::ApplicationOctetStream);
  check(st(HttpMime)::SuffixIso,st(HttpMime)::Type::ApplicationOctetStream);
  check(st(HttpMime)::SuffixImg,st(HttpMime)::Type::ApplicationOctetStream);
  check(st(HttpMime)::SuffixMsi,st(HttpMime)::Type::ApplicationOctetStream);
  check(st(HttpMime)::SuffixMsp,st(HttpMime)::Type::ApplicationOctetStream);
  check(st(HttpMime)::SuffixMsm,st(HttpMime)::Type::ApplicationOctetStream);
  check(st(HttpMime)::SuffixImg,st(HttpMime)::Type::ApplicationOctetStream);

  check(st(HttpMime)::SuffixMid,st(HttpMime)::Type::AudioMidi);
  check(st(HttpMime)::SuffixMidi,st(HttpMime)::Type::AudioMidi);
  check(st(HttpMime)::SuffixKar,st(HttpMime)::Type::AudioMidi);

  check(st(HttpMime)::SuffixMp3,st(HttpMime)::Type::AudioMpeg);

  check(st(HttpMime)::SuffixOgg,st(HttpMime)::Type::AudioOgg);

  check(st(HttpMime)::SuffixM4a,st(HttpMime)::Type::AudioXM4a);

  check(st(HttpMime)::SuffixRa,st(HttpMime)::Type::AudioXRealAudio);

  check(st(HttpMime)::Suffix3Gpp,st(HttpMime)::Type::Video3Gpp);
  check(st(HttpMime)::Sufix3Gp,st(HttpMime)::Type::Video3Gpp);

  check(st(HttpMime)::SuffixTs,st(HttpMime)::Type::VideoMp2t);

  check(st(HttpMime)::SuffixMp4,st(HttpMime)::Type::VideoMp4);

  check(st(HttpMime)::SuffixMpeg,st(HttpMime)::Type::VideoMpeg);
  check(st(HttpMime)::SuffixMpg,st(HttpMime)::Type::VideoMpeg);

  check(st(HttpMime)::SuffixMov,st(HttpMime)::Type::VidoQuicktime);

  check(st(HttpMime)::SuffixWebm,st(HttpMime)::Type::VideoWebm);

  check(st(HttpMime)::SuffixFlv,st(HttpMime)::Type::VideoXflv);

  check(st(HttpMime)::SuffixM4V,st(HttpMime)::Type::VideoXM4v);

  check(st(HttpMime)::SuffixMng,st(HttpMime)::Type::VideoXMng);

  check(st(HttpMime)::SuffixAsx,st(HttpMime)::Type::VideoXMsAsf);
  check(st(HttpMime)::SuffixAsf,st(HttpMime)::Type::VideoXMsAsf);

  check(st(HttpMime)::SuffixWmv,st(HttpMime)::Type::VideoXMsWmv);

  check(st(HttpMime)::SuffixAvi,st(HttpMime)::Type::VideoXMsVideo);

  TEST_OK("[TestHttpMime suffix to id case100]");
}
