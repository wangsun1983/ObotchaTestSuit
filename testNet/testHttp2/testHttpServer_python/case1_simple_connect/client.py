import httpx

client = httpx.Client(headers={"User-Agent": "hello/world"},http1=False, http2=True)
# 之后的使用方式和requests一样
# post
#result = client.post(url,json=data, headers=headers, cookies=cookies
#                                 ).json()
# get
result = client.get("http://127.0.0.1:8080/aaa").text

client.post("http://127.0.0.1:8080/aaa",data=str(result).encode('utf-8'))
print(result)