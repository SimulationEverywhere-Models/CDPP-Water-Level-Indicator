[top]
components : adc@Adc 
out : DigOut ToBuzz levelOut 
in : SIn 
Link : SIn SIn@adc
Link : DigOut@adc DigOut
Link : ToBuzz@adc ToBuzz
Link : levelOut@adc levelOut

[adc]
preparation : 00:00:10:000


