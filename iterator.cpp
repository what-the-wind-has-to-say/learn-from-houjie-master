//iterator需要遵循的原则
//1 iterator_category() 移动规则 例如random_access_iterator_tag
//2 difference_type 距离
//3 value_type 元素的类型
//4 reference
//5 pointer
//算法algorithm需要知道iterator的5个特征
//通过萃取机traits(中间层)
//traits中用到偏特化的方式 可以区别传入的迭代器为class或者pointer