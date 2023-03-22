## SMTP protocol

SMTP protocol is used for sending emails. 

SMTP, POP3 and IMAP are in application layer 

TCP ??? in the transport layer

# lab solution 

!First of all connect to university guest wifi!

write this command to find the SMTP servers of gmail
    $ dig gmail.com MX
    (choose of the the provided links. In my case it will be alt4.gmail-smtp-in.l.google.com)

write this command to connect to that SMTP
    $ telnet alt4.gmail-smtp-in.l.google.com 25

once you are connected you can freely write your commands. First write this 
    EHLO alt4.gmail-smtp-in.l.google.com
    (idk what this does)
    
next write who you are for the email service
    MAIL FROM: <yourEmail@tesla.com>

after that establish a connection to your own gmail email
    RCPT TO: <your gmail>

finally write 
    DATA

and fill in an email you want to send
    From: Your Name <yourEmail@tesla.com>
    Subject: object
    
    beepboop
    
to finish writing you email, end it with a lonely dot(.) at the bottom

this is it.
