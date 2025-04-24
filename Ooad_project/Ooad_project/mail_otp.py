import smtplib
import ssl
import sys

try:
    port = 587  # For starttls
    smtp_server = "smtp.gmail.com"
    sender_email = "ccbasketpesuniversity@gmail.com"  # Your email
    receiver_email = sys.argv[1] + "@gmail.com" # Full email passed directly, no appending @gmail.com
    password = "itsr mfyd obdk xvei"  # App password

    message = f"""\
Subject: OTP for CC Basket Account

Dear {sys.argv[3]},

Welcome to CC Basket pes university 

Your OTP is {sys.argv[2]}.
"""

    context = ssl.create_default_context()
    with smtplib.SMTP(smtp_server, port) as server:
        server.ehlo()
        server.starttls(context=context)
        server.ehlo()
        server.login(sender_email, password)
        server.sendmail(sender_email, receiver_email, message)

    with open(".junk", "w") as file:
        file.write(str(1))

except Exception as e:
    with open(".junk", "w") as file:
        file.write(str(-1))
    print("Error:", e)  # Optional: helps in debugging
