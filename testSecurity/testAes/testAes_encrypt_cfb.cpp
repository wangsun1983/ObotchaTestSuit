#include "Aes.hpp"
#include "SecretKeyCreator.hpp"
#include "FileOutputStream.hpp"
#include "CipherCreator.hpp"
#include "Md.hpp"
#include "TestLog.hpp"

using namespace obotcha;

//openssl Aes-Cfb -e -nosalt -in ./tmp/Aes_encrypt_Cfb_data -out decode.txt -kfile tmp/test_Aes_encrypt_Cfb_enckey

void testAesEncryptCfb() {
  //create test data
  File data = File::New("./tmp/Aes_encrypt_Cfb_data");
  if(!data->exists()) {
    data->createNewFile();
  }

  FileOutputStream stream = FileOutputStream::New(data);
  String str = String::New("abcdefghi");
  stream->open();
  stream->write(str->toByteArray());
  stream->close();

  String key = String::New("1234567812345678");
  Md md5sum = Md::New(st(Md)::Type::Md5);
  String testDataMd5 = md5sum->encodeFile(data);

  //pkcs5
  while(1) {
    SecretKey secretKey = st(SecretKeyCreator)::getInstance("AES/CFB1");
    secretKey->generate(String::New("./tmp/test_Aes_encrypt_Cfb1_deckey"),
                        String::New("./tmp/test_Aes_encrypt_Cfb1_enckey"),
                        key);

    SecretKey enckey = st(SecretKeyCreator)::getInstance("AES/CFB1");
    enckey->loadEncryptKey("./tmp/test_Aes_encrypt_Cfb1_enckey");
    Cipher Aes = st(CipherCreator)::getInstance("AES/CFB1/PKCS5Padding");
    Aes->init(st(Cipher)::Mode::Encrypt,enckey);
    Aes->encryptFile(data,"./tmp/Aes_encrypt_Cfb1_outdata_pksc5");

    SecretKey deckey = st(SecretKeyCreator)::getInstance("AES/CFB1");
    deckey->loadDecryptKey("./tmp/test_Aes_encrypt_Cfb1_deckey");
    Cipher Aes2 = st(CipherCreator)::getInstance("AES/CFB1/PKCS5Padding");
    Aes2->init(st(Cipher)::Mode::Decrypt,deckey);
    Aes2->decryptFile("./tmp/Aes_encrypt_Cfb1_outdata_pksc5","./tmp/Aes_encrypt_Cfb1_outdata_pksc5_dec");
    String result = md5sum->encodeFile(File::New("./tmp/Aes_encrypt_Cfb1_outdata_pksc5_dec"));

    if(!result->equals(testDataMd5)) {
      TEST_FAIL("[TestAes Cfb1 PKCS5Padding case1]");
    }
    TEST_OK("[TestAes Cfb1 PKCS5Padding case1]");
    break;
  }

  while(1) {
    SecretKey secretKey = st(SecretKeyCreator)::getInstance("AES/CFB8");
    secretKey->generate(String::New("./tmp/test_Aes_encrypt_Cfb8_deckey"),
                        String::New("./tmp/test_Aes_encrypt_Cfb8_enckey"),
                        key);

    SecretKey enckey = st(SecretKeyCreator)::getInstance("AES/CFB8");
    enckey->loadEncryptKey("./tmp/test_Aes_encrypt_Cfb8_enckey");
    Cipher Aes = st(CipherCreator)::getInstance("AES/CFB8/PKCS5Padding");
    Aes->init(st(Cipher)::Mode::Encrypt,enckey);
    Aes->encryptFile(data,"./tmp/Aes_encrypt_Cfb8_outdata_pksc5");
    SecretKey deckey = st(SecretKeyCreator)::getInstance("AES/CFB8");
    deckey->loadDecryptKey("./tmp/test_Aes_encrypt_Cfb8_deckey");
    Cipher Aes2 = st(CipherCreator)::getInstance("AES/CFB8/PKCS5Padding");
    Aes2->init(st(Cipher)::Mode::Decrypt,deckey);
    Aes2->decryptFile("./tmp/Aes_encrypt_Cfb8_outdata_pksc5","./tmp/Aes_encrypt_Cfb8_outdata_pksc5_dec");
    String result = md5sum->encodeFile(File::New("./tmp/Aes_encrypt_Cfb8_outdata_pksc5_dec"));

    if(!result->equals(testDataMd5)) {
      TEST_FAIL("[TestAes Cfb1 case2]");
    }
    TEST_OK("[TestAes Cfb1 case2]");
    break;
  }

  while(1) {
    SecretKey secretKey = st(SecretKeyCreator)::getInstance("AES/CFB8");
    secretKey->generate(String::New("./tmp/test_Aes_encrypt_Cfb128_deckey"),
                        String::New("./tmp/test_Aes_encrypt_Cfb128_enckey"),
                        key);

    SecretKey enckey = st(SecretKeyCreator)::getInstance("AES/CFB128");
    enckey->loadEncryptKey("./tmp/test_Aes_encrypt_Cfb128_enckey");
    Cipher Aes = st(CipherCreator)::getInstance("AES/CFB128/PKCS5Padding");
    Aes->init(st(Cipher)::Mode::Encrypt,enckey);
    Aes->encryptFile(data,"./tmp/Aes_encrypt_Cfb128_outdata_pksc5");
    SecretKey deckey = st(SecretKeyCreator)::getInstance("AES/CFB128");
    deckey->loadDecryptKey("./tmp/test_Aes_encrypt_Cfb128_deckey");
    Cipher Aes2 = st(CipherCreator)::getInstance("AES/CFB128/PKCS5Padding");
    Aes2->init(st(Cipher)::Mode::Decrypt,deckey);
    Aes2->decryptFile("./tmp/Aes_encrypt_Cfb128_outdata_pksc5","./tmp/Aes_encrypt_Cfb128_outdata_pksc5_dec");
    String result = md5sum->encodeFile(File::New("./tmp/Aes_encrypt_Cfb128_outdata_pksc5_dec"));

    if(!result->equals(testDataMd5)) {
      TEST_FAIL("[TestAes Cfb1 case3]");
    }
    break;
  }

  //-
    //create a test data
    //pkcs5
    while(1) {
      SecretKey secretKey = st(SecretKeyCreator)::getInstance("AES/CFB1");
      secretKey->generate(String::New("./tmp/test_Aes_encrypt_Cfb1_deckey"),
                          String::New("./tmp/test_Aes_encrypt_Cfb1_enckey"),
                          key);

      SecretKey enckey = st(SecretKeyCreator)::getInstance("AES/CFB1");
      enckey->loadEncryptKey("./tmp/test_Aes_encrypt_Cfb1_enckey");
      Cipher Aes = st(CipherCreator)::getInstance("AES/CFB1/PKCS5Padding");
      Aes->init(st(Cipher)::Mode::Encrypt,enckey);
      Aes->encryptFile(data,"./tmp/Aes_encrypt_Cfb1_outdata_pksc5");
      SecretKey deckey = st(SecretKeyCreator)::getInstance("AES/CFB1");
      deckey->loadDecryptKey("./tmp/test_Aes_encrypt_Cfb1_deckey");
      Cipher Aes2 = st(CipherCreator)::getInstance("AES/CFB1/PKCS5Padding");
      Aes2->init(st(Cipher)::Mode::Decrypt,deckey);
      Aes2->decryptFile("./tmp/Aes_encrypt_Cfb1_outdata_pksc5","./tmp/Aes_encrypt_Cfb1_outdata_pksc5_dec");
      String result = md5sum->encodeFile(File::New("./tmp/Aes_encrypt_Cfb1_outdata_pksc5_dec"));

      if(!result->equals(testDataMd5)) {
        TEST_FAIL("[TestAes Cfb1 PKCS5Padding case1]");
      }
      break;
    }

    while(1) {
      SecretKey secretKey = st(SecretKeyCreator)::getInstance("AES/CFB8");
      secretKey->generate(String::New("./tmp/test_Aes_encrypt_Cfb8_deckey"),
                          String::New("./tmp/test_Aes_encrypt_Cfb8_enckey"),
                          key);

      SecretKey enckey = st(SecretKeyCreator)::getInstance("AES/CFB8");
      enckey->loadEncryptKey("./tmp/test_Aes_encrypt_Cfb8_enckey");
      Cipher Aes = st(CipherCreator)::getInstance("AES/CFB8/PKCS5Padding");
      Aes->init(st(Cipher)::Mode::Encrypt,enckey);
      Aes->encryptFile(data,"./tmp/Aes_encrypt_Cfb8_outdata_pksc5");
      SecretKey deckey = st(SecretKeyCreator)::getInstance("AES/CFB8");
      deckey->loadDecryptKey("./tmp/test_Aes_encrypt_Cfb8_deckey");
      Cipher Aes2 = st(CipherCreator)::getInstance("AES/CFB8/PKCS5Padding");
      Aes2->init(st(Cipher)::Mode::Decrypt,deckey);
      Aes2->decryptFile("./tmp/Aes_encrypt_Cfb8_outdata_pksc5","./tmp/Aes_encrypt_Cfb8_outdata_pksc5_dec");
      String result = md5sum->encodeFile(File::New("./tmp/Aes_encrypt_Cfb8_outdata_pksc5_dec"));

      if(!result->equals(testDataMd5)) {
        TEST_FAIL("[TestAes Cfb1 case2]");
      }
      break;
    }

    while(1) {
      SecretKey secretKey = st(SecretKeyCreator)::getInstance("AES/CFB8");
      secretKey->generate(String::New("./tmp/test_Aes_encrypt_Cfb128_deckey"),
                          String::New("./tmp/test_Aes_encrypt_Cfb128_enckey"),
                          key);

      SecretKey enckey = st(SecretKeyCreator)::getInstance("AES/CFB128");
      enckey->loadEncryptKey("./tmp/test_Aes_encrypt_Cfb128_enckey");
      Cipher Aes = st(CipherCreator)::getInstance("AES/CFB128/PKCS5Padding");
      Aes->init(st(Cipher)::Mode::Encrypt,enckey);
      Aes->encryptFile(data,"./tmp/Aes_encrypt_Cfb128_outdata_pksc5");
      SecretKey deckey = st(SecretKeyCreator)::getInstance("AES/CFB128");
      deckey->loadDecryptKey("./tmp/test_Aes_encrypt_Cfb128_deckey");
      Cipher Aes2 = st(CipherCreator)::getInstance("AES/CFB128/PKCS5Padding");
      Aes2->init(st(Cipher)::Mode::Decrypt,deckey);
      Aes2->decryptFile("./tmp/Aes_encrypt_Cfb128_outdata_pksc5","./tmp/Aes_encrypt_Cfb128_outdata_pksc5_dec");
      String result = md5sum->encodeFile(File::New("./tmp/Aes_encrypt_Cfb128_outdata_pksc5_dec"));

      if(!result->equals(testDataMd5)) {
        TEST_FAIL("[TestAes Cfb1 case3]");
      }
      break;
    }

    // random key
    while(1) {
      SecretKey secretKey = st(SecretKeyCreator)::getInstance("AES/CFB1");
      secretKey->generate(String::New("./tmp/test_Aes_encrypt_Cfb1_random_deckey"),
                          String::New("./tmp/test_Aes_encrypt_Cfb1_random_enckey"));


      SecretKey enckey = st(SecretKeyCreator)::getInstance("AES/CFB1");
      enckey->loadEncryptKey("./tmp/test_Aes_encrypt_Cfb1_random_enckey");
      Cipher Aes = st(CipherCreator)::getInstance("AES/CFB1/PKCS5Padding");
      Aes->init(st(Cipher)::Mode::Encrypt,enckey);
      Aes->encryptFile(data,"./tmp/Aes_encrypt_Cfb1_random_outdata_pksc5");

      SecretKey deckey = st(SecretKeyCreator)::getInstance("AES/CFB1");
      deckey->loadDecryptKey("./tmp/test_Aes_encrypt_Cfb1_random_deckey");
      Cipher Aes2 = st(CipherCreator)::getInstance("AES/CFB1/PKCS5Padding");
      Aes2->init(st(Cipher)::Mode::Decrypt,deckey);
      Aes2->decryptFile("./tmp/Aes_encrypt_Cfb1_random_outdata_pksc5","./tmp/Aes_encrypt_Cfb1_random_outdata_pksc5_dec");
      String result = md5sum->encodeFile(File::New("./tmp/Aes_encrypt_Cfb1_random_outdata_pksc5_dec"));

      if(!result->equals(testDataMd5)) {
        TEST_FAIL("[TestAes Cfb4 PKCS5Padding case1]");
      }
      break;
    }

    while(1) {
      SecretKey secretKey = st(SecretKeyCreator)::getInstance("AES/CFB8");
      secretKey->generate(String::New("./tmp/test_Aes_encrypt_Cfb8_random_deckey"),
                          String::New("./tmp/test_Aes_encrypt_Cfb8_random_enckey"));


      SecretKey enckey = st(SecretKeyCreator)::getInstance("AES/CFB8");
      enckey->loadEncryptKey("./tmp/test_Aes_encrypt_Cfb8_random_enckey");
      Cipher Aes = st(CipherCreator)::getInstance("AES/CFB8/PKCS5Padding");
      Aes->init(st(Cipher)::Mode::Encrypt,enckey);
      Aes->encryptFile(data,"./tmp/Aes_encrypt_Cfb8_random_outdata_pksc5");

      SecretKey deckey = st(SecretKeyCreator)::getInstance("AES/CFB8");
      deckey->loadDecryptKey("./tmp/test_Aes_encrypt_Cfb8_random_deckey");
      Cipher Aes2 = st(CipherCreator)::getInstance("AES/CFB8/PKCS5Padding");
      Aes2->init(st(Cipher)::Mode::Decrypt,deckey);
      Aes2->decryptFile("./tmp/Aes_encrypt_Cfb8_random_outdata_pksc5","./tmp/Aes_encrypt_Cfb8_random_outdata_pksc5_dec");
      String result = md5sum->encodeFile(File::New("./tmp/Aes_encrypt_Cfb8_random_outdata_pksc5_dec"));

      if(!result->equals(testDataMd5)) {
        TEST_FAIL("[TestAes Cfb5 case2]");
      }
      break;
    }

    while(1) {
      SecretKey secretKey = st(SecretKeyCreator)::getInstance("AES/CFB8");
      secretKey->generate(String::New("./tmp/test_Aes_encrypt_Cfb128_random_deckey"),
                          String::New("./tmp/test_Aes_encrypt_Cfb128_random_enckey"));


      SecretKey enckey = st(SecretKeyCreator)::getInstance("AES/CFB128");
      enckey->loadEncryptKey("./tmp/test_Aes_encrypt_Cfb128_random_enckey");
      Cipher Aes = st(CipherCreator)::getInstance("AES/CFB128/PKCS5Padding");
      Aes->init(st(Cipher)::Mode::Encrypt,enckey);
      Aes->encryptFile(data,"./tmp/Aes_encrypt_Cfb128_random_outdata_pksc5");

      SecretKey deckey = st(SecretKeyCreator)::getInstance("AES/CFB128");
      deckey->loadDecryptKey("./tmp/test_Aes_encrypt_Cfb128_random_deckey");
      Cipher Aes2 = st(CipherCreator)::getInstance("AES/CFB128/PKCS5Padding");
      Aes2->init(st(Cipher)::Mode::Decrypt,deckey);
      Aes2->decryptFile("./tmp/Aes_encrypt_Cfb128_random_outdata_pksc5","./tmp/Aes_encrypt_Cfb128_random_outdata_pksc5_dec");
      String result = md5sum->encodeFile(File::New("./tmp/Aes_encrypt_Cfb128_random_outdata_pksc5_dec"));

      if(!result->equals(testDataMd5)) {
        TEST_FAIL("[TestAes Cfb6 case3]");
      }
      break;
    }

    TEST_OK("[TestAes Cfb case100]");
}
