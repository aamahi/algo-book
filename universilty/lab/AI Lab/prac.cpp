        main()
        {
            ///table1
            QueueType st;
            if(st.IsEmpty)
            {
                cout << "Queue is Empty" << endl;
            }
            else
            {
                cout << "Queue isn't empty" << endl;
            }
            ItemType item;
            item.Initialize(5);
            st.Enqueue(item);
            ItemType item1;
            item1.Initialize(7);
            st.Enqueue(item1);
            ItemType item2;
            item2.Initialize(4);
            st.Enqueue(item2);
            ItemType item3;
            item3.Initialize(2);
            st.Enqueue(item3);
            if(st.IsEmpty)
            {
                cout << "Queue is Empty" << endl;
            }
            else
            {
                cout << "Queue isn't empty" << endl;
            }
            if(st.IsFull)
            {
                cout << "Queue is full" << endl;
            }
            else
            {
                cout << "Queue isn't full" << endl;
            }


            ///table2
            while(!isEmpty())
            {
                st.PrintQueue();
            }


            ///table3
            item.Initialize(5);
            st.Enqueue(item);
            item1.Initialize(7);
            st.Enqueue(item1);
            item2.Initialize(4);
            st.Enqueue(item2);
            item3.Initialize(2);
            st.Enqueue(item3);
            ItemType item4;
            item4.Initialize(6);
            st.Enqueue(item4);
            if(st.IsFull)
            {
                cout << "Queue is full" << endl;
            }
            else
            {
                cout << "Queue isn't full" << endl;
            }
            ItemType item5;
            item5.Initialize(8);
            st.Enqueue(item5);
            st.Dequeue();
            st.Dequeue();
            while(!isEmpty())
            {
                st.PrintQueue();
            }
            st.Dequeue();
            st.Dequeue();
            st.Dequeue();
            while(!isEmpty())
            {
                st.PrintQueue();
            }
            st.Dequeue();
        }
