# Zeroc ICE

## ICE 3.6 Demo
- VC12 中ice_builder Build失败的工程配置问题
通用属性-> Ice_builder, 以Ice/Hello为例
Failed：
`Output Directory:	.\generated\server`
Success:
`Output Directory:	$(MSBuildProjectDirectory)\generated\server`
貌似不是这个问题， 似乎强制生成一遍得到目录就可以了
