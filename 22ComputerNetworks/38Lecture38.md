# How any website opens up on browser
Q. What happens when you access any website on your browser?

A.
- We contact a DNS server on port 53 to get the IP address of the website.
  - DNS calls DNS Recursive Resolver: It resolves the domain name step by step to figure out the IP address.
  - if the website ends with .com, DRR will call the DNS tracking all .com IPs.
  - Once IP is figured out it is then sent to the browser.
- Browser will attempt to establish an HTTPS (TCP 3-way handshake happening under the hood) connection with the Ip:443.
- once connection is established, browser will make a request for the page.
-  browser will render the page using DOM.
- Connection will be closed. 
- Once front-end is rendered, it interacts with the website's back-end.

## Browser Cache
Any frequently visited website is cached in browser to display it without going out and looking for the website over the internet. 
- If a page is present in cache, it might get stale after some time.
- 