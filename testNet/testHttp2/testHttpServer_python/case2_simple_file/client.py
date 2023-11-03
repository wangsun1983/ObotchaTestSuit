import httpx
HTTPX_DEBUG=1

client = httpx.Client(headers={"User-Agent": "hello/world"},http1=False, http2=True,trust_env=False)
# 之后的使用方式和requests一样
# post
#result = client.post(url,json=data, headers=headers, cookies=cookies
#                                 ).json()
# get
timeout = httpx.Timeout(5)
files = {'upload-file': ('data', open('./tmp/testdata', 'rb'), 'text/plain')}
resp = client.post("http://127.0.0.1:8080/aaa",files=files,timeout=timeout)
#client.post("http://127.0.0.1:8080/aaa",data=str("abcd").encode('utf-8'))
print("!!!!!!!!!!!resp is :",resp.text)

