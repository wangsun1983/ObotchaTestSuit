#include "Des.hpp"
#include "SecretKeyCreator.hpp"
#include "FileOutputStream.hpp"
#include "CipherCreator.hpp"
#include "Md.hpp"
#include "TestLog.hpp"

using namespace obotcha;

//openssl des-cbc -e -nosalt -in ./tmp/des_encrypt_cbc_data -out decode.txt -kfile tmp/test_des_encrypt_cbc_enckey

void testDesEncryptCbc() {
  //create test data
  File data = createFile("./tmp/des_encrypt_cbc_data");
  if(!data->exists()) {
    data->createNewFile();
  }

  FileOutputStream stream = createFileOutputStream(data);
  String str = createString("abcdefghi");
  stream->open();
  stream->write(str->toByteArray());
  stream->close();

  String key = createString("12345678");
  Md md5sum = createMd(st(Md)::Md5);
  String testDataMd5 = md5sum->encodeFile(data);

  while(1) {
    //create a test data
    SecretKey secretKey = st(SecretKeyCreator)::getInstance("DES");
    secretKey->generate(createString("./tmp/test_des_encrypt_cbc_deckey"),
                        createString("./tmp/test_des_encrypt_cbc_enckey"),
                        key);

    //pkcs5
    while(1) {
      SecretKey enckey = st(SecretKeyCreator)::getInstance("DES");
      enckey->loadEncryptKey("./tmp/test_des_encrypt_cbc_enckey");
      Cipher des = st(CipherCreator)::getInstance("DES/CBC/PKCS5Padding");
      des->init(st(Cipher)::Encrypt,enckey);
      des->encryptFile(data,"./tmp/des_encrypt_cbc_outdata_pksc5");

      SecretKey deckey = st(SecretKeyCreator)::getInstance("DES");
      deckey->loadDecryptKey("./tmp/test_des_encrypt_cbc_deckey");
      Cipher des2 = st(CipherCreator)::getInstance("DES/CBC/PKCS5Padding");
      des2->init(st(Cipher)::Decrypt,deckey);
      des2->decryptFile("./tmp/des_encrypt_cbc_outdata_pksc5","./tmp/des_encrypt_cbc_outdata_pksc5_dec");
      String result = md5sum->encodeFile(createFile("./tmp/des_encrypt_cbc_outdata_pksc5_dec"));

      if(!result->equals(testDataMd5)) {
        TEST_FAIL("[TestDes cbc PKCS5Padding case1]");
      }
      break;
    }

    while(1) {
      SecretKey enckey = st(SecretKeyCreator)::getInstance("DES");
      enckey->loadEncryptKey("./tmp/test_des_encrypt_cbc_enckey");
      Cipher des = st(CipherCreator)::getInstance("DES/CBC/PKCS7Padding");
      des->init(st(Cipher)::Encrypt,enckey);
      des->encryptFile(data,"./tmp/des_encrypt_cbc_outdata_pksc7");

      SecretKey deckey = st(SecretKeyCreator)::getInstance("DES");
      deckey->loadDecryptKey("./tmp/test_des_encrypt_cbc_deckey");
      Cipher des2 = st(CipherCreator)::getInstance("DES/CBC/PKCS7Padding");
      des2->init(st(Cipher)::Decrypt,deckey);
      des2->decryptFile("./tmp/des_encrypt_cbc_outdata_pksc7","./tmp/des_encrypt_cbc_outdata_pksc7_dec");
      String result = md5sum->encodeFile(createFile("./tmp/des_encrypt_cbc_outdata_pksc7_dec"));

      if(!result->equals(testDataMd5)) {
        TEST_FAIL("[TestDes cbc PKCS5Padding case1]");
      }
      break;
    }

    while(1) {
      SecretKey enckey = st(SecretKeyCreator)::getInstance("DES");
      enckey->loadEncryptKey("./tmp/test_des_encrypt_cbc_enckey");
      Cipher des = st(CipherCreator)::getInstance("DES/cbc/PKCS7Padding");
      des->init(st(Cipher)::Encrypt,enckey);
      des->encryptFile(data,"./tmp/des_encrypt_cbc_outdata_pksc7");

      SecretKey deckey = st(SecretKeyCreator)::getInstance("DES");
      deckey->loadDecryptKey("./tmp/test_des_encrypt_cbc_deckey");
      Cipher des2 = st(CipherCreator)::getInstance("DES/cbc/PKCS7Padding");
      des2->init(st(Cipher)::Decrypt,deckey);
      des2->decryptFile("./tmp/des_encrypt_cbc_outdata_pksc7","./tmp/des_encrypt_cbc_outdata_pksc7_dec");
      String result = md5sum->encodeFile(createFile("./tmp/des_encrypt_cbc_outdata_pksc7_dec"));

      if(!result->equals(testDataMd5)) {
        TEST_FAIL("[TestDes cbc PKCS7Padding case2]");
      }
      break;
    }

    while(1) {
      SecretKey enckey = st(SecretKeyCreator)::getInstance("DES");
      enckey->loadEncryptKey("./tmp/test_des_encrypt_cbc_enckey");
      Cipher des = st(CipherCreator)::getInstance("DES/cbc/ZeroPading");
      des->init(st(Cipher)::Encrypt,enckey);
      des->encryptFile(data,"./tmp/des_encrypt_cbc_outdata_pksc0");

      SecretKey deckey = st(SecretKeyCreator)::getInstance("DES");
      deckey->loadDecryptKey("./tmp/test_des_encrypt_cbc_deckey");
      Cipher des2 = st(CipherCreator)::getInstance("DES/cbc/ZeroPading");
      des2->init(st(Cipher)::Decrypt,deckey);
      des2->decryptFile("./tmp/des_encrypt_cbc_outdata_pksc0","./tmp/des_encrypt_cbc_outdata_pksc0_dec");
      String result = md5sum->encodeFile(createFile("./tmp/des_encrypt_cbc_outdata_pksc0_dec"));

      if(!result->equals(testDataMd5)) {
        TEST_FAIL("[TestDes cbc ZeroPading case3]");
      }
      break;
    }

    break;
  }

  TEST_OK("[TestDes cbc case100]");
}
