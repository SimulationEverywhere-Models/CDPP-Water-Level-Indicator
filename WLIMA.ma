[top]
components : adc@Adc colordecider@Colordecider buzzer@Buzzer displaypanel@Displaypanel 
out : buzzOut redOut greenOut yellowOut DPLevel 
in : SIn 
Link : SIn SIn@adc
Link : DigOut@adc CDIn1@colordecider
Link : ToBuzz@adc buzzIn@buzzer
Link : levelOut@adc CDIn2@colordecider
Link : CDOut@colordecider DPIn1@displaypanel
Link : L_Out@colordecider DPIn2@displaypanel
Link : DPLevel@displaypanel DPLevel
Link : yellowOut@displaypanel yellowOut
Link : greenOut@displaypanel greenOut
Link : redOut@displaypanel redOut
Link : buzzOut@buzzer buzzOut

[adc]
preparation : 00:00:10:000

[colordecider]
decision : 00:00:05:000

[buzzer]
buzz : 00:00:10:000
[displaypanel]
display : 00:00:02:000


