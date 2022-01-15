//提高迭代器iterator可以遍历整个容器
//底层红黑树,禁止通过iterator修改赋值
//set的key可以重复,multiset的key不能重复
//insert()分别调用的是rb_tree的insert_unique(),insert_equal()
//set的迭代器是红黑树的const iterator
//container adaoter 功能适配器

//map底层红黑树，key不可修改，const key，可以修改data
//map的迭代器是红黑树的 iterator