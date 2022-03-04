package main

import (
	"io"
	"mime/multipart"
	"net/http"
  "log"
  "io/ioutil"
  "strings"
  "archive/zip"
  //"bytes"
  "../../../../common"
  "strconv"
  "os"
  "fmt"
  "time"
)

func main() {
  port := testnet.GetEnvPort()
  fmt.Println("port is ",port)

	testHandler := http.HandlerFunc(onTest)
	http.Handle("/test", testHandler)
	http.ListenAndServe(":" + strconv.Itoa(port) , nil)
  port = port + 1
  testnet.SetEnvPort(port)
}

func close() {
  time.Sleep(time.Duration(1)*time.Second)
  os.Exit(0);
}

func onTest(w http.ResponseWriter, r *http.Request) {
	err := r.ParseMultipartForm(32 << 20) // maxMemory 32MB
  log.Printf("err is %v \n",err)

  if r.MultipartForm.Value != nil {
      parseMultipartFormValue(r.MultipartForm.Value)
  }

  if r.MultipartForm.File != nil {
      parseMultipartFormFile(r, r.MultipartForm.File)
  }
	var response = "";
	for formName, values := range r.MultipartForm.Value {
 		 log.Printf("Value formname: %s\n", formName)
 		 for i, value := range values {
 				 log.Printf("      formdata[%d]: content=[%s]\n", i, value)
 				 //m := make(map[string]string)
 				 //_ = json.NewDecoder(strings.NewReader(value)).Decode(&m)
 				 //log.Printf("      formdata[%d]: json=[%v]\n", i, value)
				 response += formName;
				 response += value;
 		 }
  }

  w.WriteHeader(http.StatusOK)
  io.WriteString(w, response)
  go close()
	return
}

// parse form data
func parseMultipartFormValue(formValues map[string][]string) {
    for formName, values := range formValues {
        log.Printf("Value formname: %s\n", formName)
        for i, value := range values {
            log.Printf("      formdata[%d]: content=[%s]\n", i, value)
            //m := make(map[string]string)
            //_ = json.NewDecoder(strings.NewReader(value)).Decode(&m)
            //log.Printf("      formdata[%d]: json=[%v]\n", i, value)
        }
    }
    return
}

// parse form file
func parseMultipartFormFile(r *http.Request, formFiles map[string][]*multipart.FileHeader) {
    for formName, _ := range formFiles {
        // func (r *Request) FormFile(key string) (multipart.File, *multipart.FileHeader, error)
        // FormFile returns the first file for the provided form key
        formFile, formFileHeader, _ := r.FormFile(formName)

        log.Printf("File formname: %s, filename: %s, file length: %d\n", formName, formFileHeader.Filename, formFileHeader.Size)

        if strings.HasSuffix(formFileHeader.Filename, ".zip") {
            zipReader, _ := zip.NewReader(formFile, formFileHeader.Size)
            for i, zipMember := range zipReader.File {
                f, _ := zipMember.Open()
                defer f.Close()

                buf, _ := ioutil.ReadAll(f)
                log.Printf("     formfile[%d]: filename=[%s], size=%d, content=[%s]\n", i, zipMember.Name, len(buf), strings.TrimSuffix(string(buf), "\n"))
            }
        } else {
            fmt.Println("sssss")
            //var b bytes.Buffer
            //_, _ = io.Copy(&b, formFile)
            //log.Printf("     formfile: content=[%s]\n", strings.TrimSuffix(b.String(), "\n"))
            of,err2 := os.Create("./tmp/file1.text")
            if err2 != nil {
              fmt.Println("create file failed")
              return
            }
            defer of.Close()
            io.Copy(of,formFile)
        }
    }
}
