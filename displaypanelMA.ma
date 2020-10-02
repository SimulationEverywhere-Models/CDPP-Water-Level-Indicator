[top]
components : displaypanel@Displaypanel 
out : redOut greenOut yellowOut DPLevel 
in : DPIn1 DPIn2 
Link : DPIn1 DPIn1@displaypanel
Link : DPIn2 DPIn2@displaypanel
Link : redOut@displaypanel redOut
Link : yellowOut@displaypanel yellowOut
Link : greenOut@displaypanel greenOut
Link : DPLevel@displaypanel DPLevel

[displaypanel]
display : 00:00:02:000


