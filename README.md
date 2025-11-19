<h1>C++ Product Recommendation System</h1>

<p>
This project is a simple item-based product recommendation engine built in C++.
It predicts which products a user may also like based on what similar users have purchased or rated.
The system uses weighted scoring and a custom recommendation logic to generate relevant suggestions.
</p>


<h2>📌 How It Works</h2>
<ol>
  <li>User selects an item from the shopping menu.</li>
  <li>The system scans all user ratings for that item.</li>
  <li>It uses those ratings as “weights” to predict similar products.</li>
  <li>Products with the highest predicted score are recommended.</li>
</ol>

<h2>📌 Technologies Used</h2>
<ul>
  <li>C++ (STL: map, vector, sorting, string)</li>
  <li>Custom recommendation logic</li>
  <li>No external libraries required</li>
</ul>


<p>Just copy the main.cpp code and run.</p>

<h2>📌 Sample Output</h2>

<pre>
********** SHOPPING MENU **********
1. Laptop
2. Mouse
3. Keyboard
4. Monitor
5. Headphones
6. Smartphone
7. Tablet
8. Smartwatch
9. Printer
...
(25+ items)

Choose an item (1-26): 1

You selected: Laptop

Recommended items based on your choice:
- Mouse (score: 4.72)
- Headphones (score: 4.55)
- Monitor (score: 4.21)
- Desk Lamp (score: 3.89)
- SSD (score: 3.80)
- Graphics Card (score: 3.74)
- Gaming Chair (score: 3.69)
- External HDD (score: 3.60)
</pre>


<h2>📌 Future Improvements</h2>
<ul>
  <li>Add shopping cart and pricing</li>
  <li>Add categories (Electronics / Mobile / Gaming)</li>
  <li>Load ratings from a file instead of hardcoding</li>
  <li>Convert into a full e-commerce backend project</li>
</ul>

<h2>📌 Author</h2>
<p>Thank You ❤️.</p>
