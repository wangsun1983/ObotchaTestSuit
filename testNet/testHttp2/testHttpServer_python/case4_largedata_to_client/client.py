import httpx
HTTPX_DEBUG=1

client = httpx.Client(headers={"User-Agent": "hello/world"},http1=False, http2=True,trust_env=False)
# 之后的使用方式和requests一样
# post
#result = client.post(url,json=data, headers=headers, cookies=cookies
#                                 ).json()
# get
result = client.get("http://127.0.0.1:8080/aaa").text
with open('./tmp/new.txt', 'w', encoding='utf-8') as f:
    f.write(result)

