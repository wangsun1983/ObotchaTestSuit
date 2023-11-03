import httpx

client = httpx.Client(headers={"User-Agent": "hello/world"},http1=False, http2=True)
# 之后的使用方式和requests一样
# post
#result = client.post(url,json=data, headers=headers, cookies=cookies
#                                 ).json()
# get
headers = {"mydata":"1"}

count = 0
while count < 1024*32:
    headers[str(count)] = str(count) + 'a'
    count = count+1

resp = client.get("http://127.0.0.1:8080/aaa",headers = headers)

#client.post("http://127.0.0.1:8080/aaa",data=str(result).encode('utf-8'))
#print(result)