#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderContentType.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void check(String suffix,int expectedId) {
  HttpMime mime = st(HttpMime)::createBySuffix(suffix);
  //mime->setSuffix(suffix);
  if(mime->getId() != expectedId) {
    TEST_FAIL("[TestHttpMime suffix to id case1],id is %d,expectedId is %d,suffix is %s",mime->getId(),expectedId,suffix->toChars());
  }
}

void testSuffixIdConvert() {
  check(st(HttpMime)::SuffixHtml,st(HttpMime)::TypeTextHtml);
  check(st(HttpMime)::SuffixHtm,st(HttpMime)::TypeTextHtml);
  check(st(HttpMime)::SuffixShtml,st(HttpMime)::TypeTextHtml);

  check(st(HttpMime)::SuffixCss,st(HttpMime)::TypeTextCss);

  check(st(HttpMime)::SuffixXml,st(HttpMime)::TypeTextXml);

  check(st(HttpMime)::SuffixGif,st(HttpMime)::TypeImageGif);

  check(st(HttpMime)::SuffixJpeg,st(HttpMime)::TypeImageJpeg);
  check(st(HttpMime)::SuffixJpg,st(HttpMime)::TypeImageJpeg);

  check(st(HttpMime)::SuffixJs,st(HttpMime)::TypeApplicationJs);

  check(st(HttpMime)::SuffixAtom,st(HttpMime)::TypeApplicationAtomXml);

  check(st(HttpMime)::SuffixRss,st(HttpMime)::TypeApplicationRss);

  check(st(HttpMime)::SuffixMml,st(HttpMime)::TypeTextMathml);

  check(st(HttpMime)::SuffixTxt,st(HttpMime)::TypeTextPlain);

  check(st(HttpMime)::SuffixJad,st(HttpMime)::TypeTextVndSunJ2meAppDes);

  check(st(HttpMime)::SuffixWml,st(HttpMime)::TypeTextVndWapWml);

  check(st(HttpMime)::SuffixHtc,st(HttpMime)::TypeTextXComponent);

  check(st(HttpMime)::SuffixPng,st(HttpMime)::TypeImagePng);

  check(st(HttpMime)::SuffixSvg,st(HttpMime)::TypeImageSvgXml);
  check(st(HttpMime)::SuffixSvgz,st(HttpMime)::TypeImageSvgXml);

  check(st(HttpMime)::SuffixTif,st(HttpMime)::TypeImageTiff);
  check(st(HttpMime)::SuffixTiff,st(HttpMime)::TypeImageTiff);

  check(st(HttpMime)::SuffixWbmp,st(HttpMime)::TypeImageVndWapWbmp);

  check(st(HttpMime)::SuffixWebp,st(HttpMime)::TypeImageWebp);

  check(st(HttpMime)::SuffixIco,st(HttpMime)::TypeImageXIcon);

  check(st(HttpMime)::SuffixJng,st(HttpMime)::TypeImageXJng);

  check(st(HttpMime)::SuffixBmp,st(HttpMime)::TypeImageXMsBmp);

  check(st(HttpMime)::SuffixWoff,st(HttpMime)::TypeApplicationFontWoff);

  check(st(HttpMime)::SuffixJar,st(HttpMime)::TypeApplicationJavaArchive);
  check(st(HttpMime)::SuffixWar,st(HttpMime)::TypeApplicationJavaArchive);
  check(st(HttpMime)::SuffixEar,st(HttpMime)::TypeApplicationJavaArchive);

  check(st(HttpMime)::SuffixJson,st(HttpMime)::TypeApplicationJson);

  check(st(HttpMime)::SuffixHqx,st(HttpMime)::TypeApplicationMaxBinhex40);

  check(st(HttpMime)::SuffixDoc,st(HttpMime)::TypeApplicationMsword);

  check(st(HttpMime)::SuffixPdf,st(HttpMime)::TypeApplicationPdf);

  check(st(HttpMime)::SuffixPs,st(HttpMime)::TypeApplicationPostScript);
  check(st(HttpMime)::SuffixEps,st(HttpMime)::TypeApplicationPostScript);
  check(st(HttpMime)::SuffixAi,st(HttpMime)::TypeApplicationPostScript);

  check(st(HttpMime)::SuffixRtf,st(HttpMime)::TypeApplicationRtf);

  check(st(HttpMime)::SuffixM3u8,st(HttpMime)::TypeApplicationVndAppleMpegurl);

  check(st(HttpMime)::SuffixKml,st(HttpMime)::TypeApplicationVndGoogleEarthKmlXml);

  check(st(HttpMime)::SuffixKmz,st(HttpMime)::TypeApplicationVndGoogleEarthKmz);

  check(st(HttpMime)::SuffixXls,st(HttpMime)::TypeApplicationVndMsExcel);

  check(st(HttpMime)::SuffixEot,st(HttpMime)::TypeApplicationVndMsFontObject);

  check(st(HttpMime)::SuffixPpt,st(HttpMime)::TypeApplicationVndMsPpt);

  check(st(HttpMime)::SuffixOdj,st(HttpMime)::TypeApplicationVndOasisOpendocGraphics);

  check(st(HttpMime)::SuffixOdp,st(HttpMime)::TypeApplicationVndOasisOpendocPresentation);

  check(st(HttpMime)::SuffixOds,st(HttpMime)::TypeApplicationVndOasisOpendocSpreadsheet);

  check(st(HttpMime)::SuffixOdt,st(HttpMime)::TypeApplicationVndOasisOpendocText);

  check(st(HttpMime)::SuffixPptx,st(HttpMime)::TypeApplicationVndOpenxmlPresentation);

  check(st(HttpMime)::SuffixXlsx,st(HttpMime)::TypeApplicationVndOpenXmlSheet);

  check(st(HttpMime)::SuffixDocx,st(HttpMime)::TypeApplicationVndOepnXmlDoc);

  check(st(HttpMime)::SuffixWmlc,st(HttpMime)::TypeApplicationVndWapWmls);

  check(st(HttpMime)::Suffix7z,st(HttpMime)::TypeApplication7z);

  check(st(HttpMime)::SuffixCco,st(HttpMime)::TypeApplicationXCocoa);

  check(st(HttpMime)::SuffixJardiff,st(HttpMime)::TypeApplicationXJavaArch);

  check(st(HttpMime)::SuffixJnlp,st(HttpMime)::TypeApplicationXJavaJnlpFile);

  check(st(HttpMime)::SuffixRun,st(HttpMime)::TypeApplicationXMakeself);

  check(st(HttpMime)::SuffixPl,st(HttpMime)::TypeApplicationXPerl);
  check(st(HttpMime)::SuffixPm,st(HttpMime)::TypeApplicationXPerl);

  check(st(HttpMime)::SuffixPrc,st(HttpMime)::TypeApplicationXPilot);
  check(st(HttpMime)::SuffixPdb,st(HttpMime)::TypeApplicationXPilot);

  check(st(HttpMime)::SuffixRar,st(HttpMime)::TypeApplicationXRarCompressed);

  check(st(HttpMime)::SuffixRpm,st(HttpMime)::TypeApplicationXReadhatPkgManager);

  check(st(HttpMime)::SuffixSea,st(HttpMime)::TypeApplicationXSea);

  check(st(HttpMime)::SuffixSwf,st(HttpMime)::TypeApplicationXShockwaveFlash);

  check(st(HttpMime)::SuffixSit,st(HttpMime)::TypeApplicationXStuffit);

  check(st(HttpMime)::SuffixTcl,st(HttpMime)::TypeApplicationXTcl);
  check(st(HttpMime)::SuffixTk,st(HttpMime)::TypeApplicationXTcl);

  check(st(HttpMime)::SuffixDer,st(HttpMime)::TypeApplicationXX509CaCert);
  check(st(HttpMime)::SuffixPem,st(HttpMime)::TypeApplicationXX509CaCert);
  check(st(HttpMime)::SuffixCrt,st(HttpMime)::TypeApplicationXX509CaCert);

  check(st(HttpMime)::SuffixXpi,st(HttpMime)::TypeApplicationXXpinstall);

  check(st(HttpMime)::SuffixXhtml,st(HttpMime)::TypeApplicationXhtmlXml);

  check(st(HttpMime)::SuffixXspf,st(HttpMime)::TypeApplicationXspfXml);

  check(st(HttpMime)::SuffixZip,st(HttpMime)::TypeApplicationZip);

  check(st(HttpMime)::SuffixBin,st(HttpMime)::TypeApplicationOctetStream);
  check(st(HttpMime)::SuffixExe,st(HttpMime)::TypeApplicationOctetStream);
  check(st(HttpMime)::SuffixDll,st(HttpMime)::TypeApplicationOctetStream);
  check(st(HttpMime)::SuffixDeb,st(HttpMime)::TypeApplicationOctetStream);
  check(st(HttpMime)::SuffixDmg,st(HttpMime)::TypeApplicationOctetStream);
  check(st(HttpMime)::SuffixIso,st(HttpMime)::TypeApplicationOctetStream);
  check(st(HttpMime)::SuffixImg,st(HttpMime)::TypeApplicationOctetStream);
  check(st(HttpMime)::SuffixMsi,st(HttpMime)::TypeApplicationOctetStream);
  check(st(HttpMime)::SuffixMsp,st(HttpMime)::TypeApplicationOctetStream);
  check(st(HttpMime)::SuffixMsm,st(HttpMime)::TypeApplicationOctetStream);
  check(st(HttpMime)::SuffixImg,st(HttpMime)::TypeApplicationOctetStream);

  check(st(HttpMime)::SuffixMid,st(HttpMime)::TypeAudioMidi);
  check(st(HttpMime)::SuffixMidi,st(HttpMime)::TypeAudioMidi);
  check(st(HttpMime)::SuffixKar,st(HttpMime)::TypeAudioMidi);

  check(st(HttpMime)::SuffixMp3,st(HttpMime)::TypeAudioMpeg);

  check(st(HttpMime)::SuffixOgg,st(HttpMime)::TypeAudioOgg);

  check(st(HttpMime)::SuffixM4a,st(HttpMime)::TypeAudioXM4a);

  check(st(HttpMime)::SuffixRa,st(HttpMime)::TypeAudioXRealAudio);

  check(st(HttpMime)::Suffix3Gpp,st(HttpMime)::TypeVideo3Gpp);
  check(st(HttpMime)::Sufix3Gp,st(HttpMime)::TypeVideo3Gpp);

  check(st(HttpMime)::SuffixTs,st(HttpMime)::TypeVideoMp2t);

  check(st(HttpMime)::SuffixMp4,st(HttpMime)::TypeVideoMp4);

  check(st(HttpMime)::SuffixMpeg,st(HttpMime)::TypeVideoMpeg);
  check(st(HttpMime)::SuffixMpg,st(HttpMime)::TypeVideoMpeg);

  check(st(HttpMime)::SuffixMov,st(HttpMime)::TypeVidoQuicktime);

  check(st(HttpMime)::SuffixWebm,st(HttpMime)::TypeVideoWebm);

  check(st(HttpMime)::SuffixFlv,st(HttpMime)::TypeVideoXflv);

  check(st(HttpMime)::SuffixM4V,st(HttpMime)::TypeVideoXM4v);

  check(st(HttpMime)::SuffixMng,st(HttpMime)::TypeVideoXMng);

  check(st(HttpMime)::SuffixAsx,st(HttpMime)::TypeVideoXMsAsf);
  check(st(HttpMime)::SuffixAsf,st(HttpMime)::TypeVideoXMsAsf);

  check(st(HttpMime)::SuffixWmv,st(HttpMime)::TypeVideoXMsWmv);

  check(st(HttpMime)::SuffixAvi,st(HttpMime)::TypeVideoXMsVideo);

  TEST_OK("[TestHttpMime suffix to id case100]");
}
