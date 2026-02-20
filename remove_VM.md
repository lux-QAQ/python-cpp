# VM 依赖移除检查清单

## 第一阶段：RuntimeContext 扩展
- [ ] RuntimeContext.hpp - 添加 is_true, equals, stack_local 接口
- [ ] RuntimeContext.cpp - 实现新接口
- [ ] VM.cpp - 在构造函数中注册 RuntimeContext

## 第二阶段：高频调用点修改
- [ ] PyList.cpp - __eq__, sort 方法
- [ ] PyTuple.cpp - __eq__ 方法
- [ ] PyObject.cpp - __ne__ 方法
- [ ] PyArgParser.hpp - bool 参数解析

## 第三阶段：Heap 相关修改
- [ ] SysModule.cpp - 移除 heap.slab().has_address()
- [ ] BuiltinsModule.cpp - 移除 heap.slab().has_address()
- [ ] 所有模块 - 使用 PYLANG_GC_PAUSE_SCOPE() 宏

## 第四阶段：Import 系统修改
- [ ] Import.cpp - 移除 truthy(VirtualMachine::the().interpreter())

## 第五阶段：PyCode 栈访问修改
- [ ] PyCode.cpp - 使用 RuntimeContext 访问栈
- [ ] GeneratorInterface.cpp - 修改栈帧访问

## 第六阶段：测试和验证
- [ ] 运行单元测试
- [ ] 运行集成测试
- [ ] 验证 PYLANG_USE_SHARED_PTR 模式
- [ ] 验证旧 VM 模式兼容性