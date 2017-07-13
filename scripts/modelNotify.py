from twilio.rest import Client

account_sid = "ACa287e11e2c4095887ad75aaf45a92123"
auth_token = "0b4d1ae0fbb1307afc8727cc7d362ffb"

client = Client(account_sid, auth_token)

client.messages.create(

    to="+16507737648",

    from_="+14159805777",

    body="Your model finished running."
    
)
