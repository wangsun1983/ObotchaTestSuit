package main

import (
	"bytes"
	"fmt"
	"io"
	"io/ioutil"
	"mime/multipart"
	"net/http"
	"os"
  "../../../../common"
  "strconv"
)

func main() {
  port := testnet.GetEnvPort()
  url := "http://127.0.0.1:" + strconv.Itoa(port) + "/mytest"
  fmt.Println("url is ",url)

  for i := 0; i < 32; i++ {
  	req, _ := newfileUploadRequest(url, nil, "file", "./tmp/testdata")
  	client := &http.Client{}
  	//fmt.Println(req)
  	resp, err := client.Do(req)

  	defer resp.Body.Close()

  	body, err := ioutil.ReadAll(resp.Body)
  	if err != nil {
  		// handle error
  	}
    fmt.Println(string(body))
  }
}

func newfileUploadRequest(uri string, params map[string]string, paramName, path string) (*http.Request, error) {
	file, err := os.Open(path)
	if err != nil {
		return nil, err
	}
	defer file.Close()

	body := &bytes.Buffer{}
	writer := multipart.NewWriter(body)
	part, err := writer.CreateFormFile(paramName, path)
	if err != nil {
		return nil, err
	}
	_, err = io.Copy(part, file)

	for key, val := range params {
		_ = writer.WriteField(key, val)
	}
	err = writer.Close()
	if err != nil {
		return nil, err
	}
	request, err := http.NewRequest("POST", uri, body)
	request.Header.Set("Content-Type", writer.FormDataContentType())
	return request, err
}
