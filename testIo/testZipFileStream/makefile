gcc = clang++

cflags = -fpic \
		-lrt \
		-I ../../../util/concurrent/include/ \
		-I ../../../io/include \
		-I ../../../util/text/include/ \
        -I ../../../util/time/include/ \
		-I ../../../lang/include \
		-I ../../../io/include \
		-I ../../../util/include/ \
		-I ../../../net/include \
		-I ../../../security/include \
		-I ../../../process/include \
		-I ../../../external/iniparser/include \
		-I ../../../external/jsoncpp/include \
		-I ../../../external/rapidxml/include \
		-I ../../../external/zlib/include \
		-I ../../../external/ccl/include \
		-I ../../../external/yaml/include \
		-I ../../../external/crc32/include \
		-I ../../../external/openssl/include \
		-I ../../../external/libco \
		-I ../../common \
		-I ../../../external/uuid/include \
		-I ../../../external/glog/include \
		-g \
		-std=c++17 \
		-fsanitize=address \
		-fno-omit-frame-pointer

external = -lpthread \
				-ldl \
				../../../out/lib/libobotcha.so \

sharelib = -Wl,-rpath=../../../out/lib/ \
           -L ../../../out/lib/ \
           -lcrypto \
           -L ../../../out/lib/ \
           -lssl \

files =
link =
libname	= testZipFileStream

everything : $(libname)

$(libname): $(link)
	clang++ *.cpp $(cflags) -o mytest $(external) $(sharelib)
