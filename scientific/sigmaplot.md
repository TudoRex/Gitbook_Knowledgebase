# 3.1 Sigmaplot
## 自动化导入
根据[Batch Processing Using SigmaPlot Automation](https://systatsoftware.com/products/sigmaplot/product-uses/sigmaplot-product-uses-batch-processing-using-sigmaplot-automation/),了解到系统自带Macro（貌似VB脚本）有这方面的实现， 可以学习

1. [Running a SigmaPlot Macro](http://www.omatrix.com/spmanual/spmacro.htm)

### WinWrap Basic脚本语言
在查看*Macro Reference*时发现有WinWrap Basic基础库， 经过上网查询发现是第三方类VBA的解决方案

## 案例
- 如何批量导入excel

根据每个xls的首sheet创建worksheet并自动画图（参考*Batch process Excel Files*宏)


分为import和plot两个阶段，import有`Import()`方法直接导入数据, plot有`CreateWizardGraph`,并且可以用**Record Macro**的方法自动生成相关代码并改造
