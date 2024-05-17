#include "Aes.hpp"
#include "SecretKeyCreator.hpp"
#include "FileOutputStream.hpp"
#include "CipherCreator.hpp"
#include "Md.hpp"
#include "TestLog.hpp"

using namespace obotcha;

//openssl AES128-cbc -e -nosalt -in ./tmp/AES128_encrypt_cbc_data -out decode.txt -kfile tmp/test_AES128_encrypt_cbc_enckey

void testAes128EncryptCbc() {
  //create test data
  File data = File::New("./tmp/AES128_encrypt_cbc_data");
  if(!data->exists()) {
    data->createNewFile();
  }

  FileOutputStream stream = FileOutputStream::New(data);
  String str = String::New("abcdefghi");
  stream->open();
  stream->write(str->toByteArray());
  stream->close();

  String key = String::New("12345678");
  Md md5sum = Md::New(st(Md)::Md5);
  String testDataMd5 = md5sum->encodeFile(data);

  while(1) {
    //create a test data

    SecretKey secretKey = st(SecretKeyCreator)::getInstance("AES128");
    secretKey->generate(String::New("./tmp/test_AES128_encrypt_cbc_deckey"),
                        String::New("./tmp/test_AES128_encrypt_cbc_enckey"),
                        key);

    //pkcs5
    while(1) {

      SecretKey enckey = st(SecretKeyCreator)::getInstance("AES128");
      enckey->loadEncryptKey("./tmp/test_AES128_encrypt_cbc_enckey");
      Cipher AES128 = st(CipherCreator)::getInstance("AES128/CBC/PKCS5Padding");
      AES128->init(st(Cipher)::Mode::Encrypt,enckey);
      AES128->encryptFile(data,"./tmp/AES128_encrypt_cbc_outdata_pksc5");

      SecretKey deckey = st(SecretKeyCreator)::getInstance("AES128");
      deckey->loadDecryptKey("./tmp/test_AES128_encrypt_cbc_deckey");
      Cipher AES1282 = st(CipherCreator)::getInstance("AES128/CBC/PKCS5Padding");
      AES1282->init(st(Cipher)::Mode::Decrypt,deckey);
      AES1282->decryptFile("./tmp/AES128_encrypt_cbc_outdata_pksc5","./tmp/AES128_encrypt_cbc_outdata_pksc5_dec");
      String result = md5sum->encodeFile(File::New("./tmp/AES128_encrypt_cbc_outdata_pksc5_dec"));

      if(!result->equals(testDataMd5)) {
        TEST_FAIL("[TestAES128 cbc PKCS5Padding case1]");
      }
      break;
    }

    while(1) {

      SecretKey enckey = st(SecretKeyCreator)::getInstance("AES128");
      enckey->loadEncryptKey("./tmp/test_AES128_encrypt_cbc_enckey");
      Cipher AES128 = st(CipherCreator)::getInstance("AES128/CBC/PKCS7Padding");
      AES128->init(st(Cipher)::Mode::Encrypt,enckey);
      AES128->encryptFile(data,"./tmp/AES128_encrypt_cbc_outdata_pksc7");

      SecretKey deckey = st(SecretKeyCreator)::getInstance("AES128");
      deckey->loadDecryptKey("./tmp/test_AES128_encrypt_cbc_deckey");
      Cipher AES1282 = st(CipherCreator)::getInstance("AES128/CBC/PKCS7Padding");
      AES1282->init(st(Cipher)::Mode::Decrypt,deckey);
      AES1282->decryptFile("./tmp/AES128_encrypt_cbc_outdata_pksc7","./tmp/AES128_encrypt_cbc_outdata_pksc7_dec");
      String result = md5sum->encodeFile(File::New("./tmp/AES128_encrypt_cbc_outdata_pksc7_dec"));

      if(!result->equals(testDataMd5)) {
        TEST_FAIL("[TestAES128 cbc PKCS5Padding case1]");
      }
      break;
    }

    while(1) {
      SecretKey enckey = st(SecretKeyCreator)::getInstance("AES128");
      enckey->loadEncryptKey("./tmp/test_AES128_encrypt_cbc_enckey");
      Cipher AES128 = st(CipherCreator)::getInstance("AES128/cbc/PKCS7Padding");
      AES128->init(st(Cipher)::Mode::Encrypt,enckey);
      AES128->encryptFile(data,"./tmp/AES128_encrypt_cbc_outdata_pksc7");

      SecretKey deckey = st(SecretKeyCreator)::getInstance("AES128");
      deckey->loadDecryptKey("./tmp/test_AES128_encrypt_cbc_deckey");
      Cipher AES1282 = st(CipherCreator)::getInstance("AES128/cbc/PKCS7Padding");
      AES1282->init(st(Cipher)::Mode::Decrypt,deckey);
      AES1282->decryptFile("./tmp/AES128_encrypt_cbc_outdata_pksc7","./tmp/AES128_encrypt_cbc_outdata_pksc7_dec");
      String result = md5sum->encodeFile(File::New("./tmp/AES128_encrypt_cbc_outdata_pksc7_dec"));

      if(!result->equals(testDataMd5)) {
        TEST_FAIL("[TestAES128 cbc PKCS7Padding case2]");
      }
      break;
    }

    while(1) {
      SecretKey enckey = st(SecretKeyCreator)::getInstance("AES128");
      enckey->loadEncryptKey("./tmp/test_AES128_encrypt_cbc_enckey");
      Cipher AES128 = st(CipherCreator)::getInstance("AES128/cbc/ZeroPading");
      AES128->init(st(Cipher)::Mode::Encrypt,enckey);
      AES128->encryptFile(data,"./tmp/AES128_encrypt_cbc_outdata_pksc0");

      SecretKey deckey = st(SecretKeyCreator)::getInstance("AES128");
      deckey->loadDecryptKey("./tmp/test_AES128_encrypt_cbc_deckey");
      Cipher AES1282 = st(CipherCreator)::getInstance("AES128/cbc/ZeroPading");
      AES1282->init(st(Cipher)::Mode::Decrypt,deckey);
      AES1282->decryptFile("./tmp/AES128_encrypt_cbc_outdata_pksc0","./tmp/AES128_encrypt_cbc_outdata_pksc0_dec");
      String result = md5sum->encodeFile(File::New("./tmp/AES128_encrypt_cbc_outdata_pksc0_dec"));

      if(!result->equals(testDataMd5)) {
        TEST_FAIL("[TestAES128 cbc ZeroPading case3]");
      }
      break;
    }

    break;
  }

  TEST_OK("[TestAES128 cbc case100]");
}
