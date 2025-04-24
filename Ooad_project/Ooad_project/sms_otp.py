from twilio.rest import Client
import sys

# Twilio credentials
account_sid = 'AC5f6b17f395b2b3dc89c41bc32c3be18c'
auth_token = '65e79b1ef5982a7dc78966ad49bd5a2e'
client = Client(account_sid, auth_token)

# Inputs
to_number = sys.argv[1]  # recipient phone number (E.164 format like +1XXXXXXXXXX)
otp = sys.argv[2]        # OTP code
name = sys.argv[3]       # Name of recipient

# Message content
message_body = f"Dear {name}, Welcome to CC Basket PES UNIVERSITY. Your OTP is {otp}"

try:
    message = client.messages.create(
        body=message_body,
        from_='+13373175301',  # <-- Your purchased Twilio number
        to=to_number
    )
    print("> OTP Sent Success ✅")
    with open(".junk", "w") as f:
        f.write("1")
except Exception as e:
    print("> OTP Sending Failure ❌")
    print("Error sending message:", e)
    with open(".junk", "w") as f:
        f.write("-1")
