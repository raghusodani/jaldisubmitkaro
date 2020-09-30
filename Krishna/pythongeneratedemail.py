import smtplib
smtplibObjc = smtplib.SMTP('smtp.gmail.com', 587)
smtplibObjc.ehlo()
smtplibObjc.starttls()
smtplibObjc.login('senderemail@gmail.com', 'password')
smtplibObjc.sendmail('senderemail@gmail.com','recieveremail@gmail.com','Subject:Hello\n This is a python generated email!!')
smtplibObjc.quit()
