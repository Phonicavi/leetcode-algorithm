###实现一个栈(具有栈的基本操作) 这个栈可以随时取出最小值  
	用两个栈 一个Vec保存数据 一个Min保存最小值  
	最小值栈Min的top表示当前最小值，在增删Vec时要同步维护Min的存储  