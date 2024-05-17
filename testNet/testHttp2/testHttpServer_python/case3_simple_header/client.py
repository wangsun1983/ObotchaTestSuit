import httpx

client = httpx.Client(headers={"User-Agent": "hello/world"},http1=False, http2=True)
# 之后的使用方式和requests一样
# post
#result = client.post(url,json=data, headers=headers, cookies=cookies
#                                 ).json()
# get
headers = {"mydata":"mydata from python"}
resp = client.get("http://127.0.0.1:8080/aaa",headers = headers)
print(resp.headers)
resp2 = client.get("http://127.0.0.1:8080/aaa",headers = headers)
print(resp2.headers)

#client.post("http://127.0.0.1:8080/aaa",data=str(result).encode('utf-8'))
#print(result)