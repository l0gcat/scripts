#!/bin/env python3

print('''
  __       __                        __       
 / /___ __/ /_  ___________ __    __/ /__ ____
/ __/\ \ / __/ / __/ __/ _ `/ |/|/ / / -_) __/
\__//_\_\\\\__/__\__/_/  \_,_/|__,__/_/\__/_/ 
           /___/  							''')

import sys, requests
from bs4 import BeautifulSoup

url = sys.argv[1]

if not url.startswith(('http://', 'https://')):
    url = 'http://' + url
if not url.endswith('/'):
    url = url + '/'

try:
    raw = requests.get(url)
except:
    url = 'https://' + url
    raw = requests.get(url)

soup = BeautifulSoup(raw.content, 'html.parser')
data = str(soup.prettify())
tag_list = data.split('\n')

print()
del raw, soup, data

for i in range(len(tag_list)):
    if '.php' in tag_list[i] or \
            '.js' in tag_list[i] or \
            '.css' in tag_list[i] or \
            '.aspx' in tag_list[i] or \
            '.html' in tag_list[i] or \
            '/*' in tag_list[i] or \
            '<!--' in tag_list[i]:
        out = tag_list[i].strip()
        print('%d : %s' % (i, out))

if input("\n[?] get robots.txt? [Y/n] : ") in ["Y", "y", ""]:
    print("\n"+requests.get(url + 'robots.txt').text)
