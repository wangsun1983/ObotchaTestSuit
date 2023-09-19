#include "Aes.hpp"
#include "SecretKeyCreator.hpp"
#include "FileOutputStream.hpp"
#include "CipherCreator.hpp"
#include "Md.hpp"
#include "TestLog.hpp"

using namespace obotcha;

//openssl AES128-ecb -e -nosalt -in ./tmp/AES128_encrypt_ecb_data -out decode.txt -kfile tmp/test_AES128_encrypt_ecb_enckey

void testRsaf4Pcks1() {
  //create test data
  File data = createFile("./tmp/RSAF4_pcks1_data");
  if(!data->exists()) {
    data->createNewFile();
  }

  FileOutputStream stream = createFileOutputStream(data);
  String str = createString("abcdefghi");
  stream->open();
  for(int i = 0;i < 1024;i++) {
      str = str->append("abcdefgh");
  }
  stream->write(str->toByteArray());
  stream->close();

  String key = createString("12345678");
  Md md5sum = createMd(st(Md)::Md5);
  String testDataMd5 = md5sum->encodeFile(data);

  while(1) {
    //create a test data
    SecretKey secretKey = st(SecretKeyCreator)::getInstance("RSA/RSAF4/PKCS1Padding");
    secretKey->generate(createString("./tmp/test_RSAF4_pcks1_encrypt_deckey"),
                        createString("./tmp/test_RSAF4_pcks1_encrypt_enckey"),
                        key);

    //pkcs5
    while(1) {
      SecretKey enckey = st(SecretKeyCreator)::getInstance("RSA/RSAF4/PKCS1Padding");
      enckey->loadEncryptKey("./tmp/test_RSAF4_pcks1_encrypt_enckey");
      Cipher AES128 = st(CipherCreator)::getInstance("RSA/RSAF4/PKCS1Padding");
      AES128->init(st(Cipher)::Mode::Encrypt,enckey);
      AES128->encryptFile(data,"./tmp/RSAF4_pcks1_encrypt_outdata");

      SecretKey deckey = st(SecretKeyCreator)::getInstance("RSA/RSAF4/PKCS1Padding");
      deckey->loadDecryptKey("./tmp/test_RSAF4_pcks1_encrypt_deckey");
      Cipher AES1282 = st(CipherCreator)::getInstance("RSA/RSAF4/PKCS1Padding");
      AES1282->init(st(Cipher)::Mode::Decrypt,deckey);
      AES1282->decryptFile("./tmp/RSAF4_pcks1_encrypt_outdata","./tmp/RSAF4_pcks1_encrypt_outdata_dec");
      String result = md5sum->encodeFile(createFile("./tmp/RSAF4_pcks1_encrypt_outdata_dec"));

      if(!result->equals(testDataMd5)) {
        TEST_FAIL("[TestRSAF4Pcks1 Ecb PKCS5Padding case1]");
      }
      break;
    }

    break;
  }
  TEST_OK("[TestRSAF4Pcks1 case100]");
}
