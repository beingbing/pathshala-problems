# Session layer
Till transport layer software engineers do not have to actively be concerned how things are done. But from Session layer, we need to design the interaction using the framework we are using.

Session, Presentation and Application layer do not have a well defined boundary or layered structure. Boundaries are very blur.

Session layer deals with the session.

## What is a Session ?
To define it we need to first define two more terms:

### Authentication
To check users authenticity. It validates if user is legitimate or not. User is who he/she says he/she is.

### Authorization
To check whether a user has authority to perform a particular action.

- Once user is authenticated during login process, a token is generated which facilitates to maintain a session.
- Every token has an expiry, once it expires, user needs to login again.
- We have a concept of refresh token as well, which is stored at BE. Once a token expires but the user still has a valid refresh token stored, then a new token is generated automatically without user taking any action and user session is continued. Websites with time sensitive subscription features do not use refresh tokens mostly.

### Webinar synchronization
In recent time, apart from authentication and authorization session layer also need to synchronize (superimpose) different components of user feed like video, audio, etc according to timestamp and convert it into a single webinar stream.

## Cookies
In user machine, the process runs in volatile memory, so if we store token with that, we loose it once the browser is closed. But to avoid it we have cookies. Browser cookies are persistent storage, as cookies are stored in persistent memory of the machine when browser is closed. 

### drawbacks of having cookies
- as cookies persistent, other websites opened in the browser can access your cookies from any other website.
- these extracted information can be used to show you targeted ads.


