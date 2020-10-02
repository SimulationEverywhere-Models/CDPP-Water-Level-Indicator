[top]
components : colordecider@Colordecider 
out : CDOut L_Out 
in : CDIn1 CDIn2 
Link : CDOut@colordecider CDOut
Link : L_Out@colordecider L_Out
Link : CDIn2 CDIn2@colordecider
Link : CDIn1 CDIn1@colordecider

[colordecider]
decision : 00:00:05:000

