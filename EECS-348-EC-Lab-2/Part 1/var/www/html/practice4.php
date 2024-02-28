<html>
<head>
    <link rel="stylesheet" href="https://people.eecs.ku.edu/~m668s124/styles.css">
</head>

<?php 
if($_POST) { 
    $num_rows = $_POST["size"]; // This is the only input from the HTML
    echo "<table style=\"table-layout: fixed; width: 100%;\">";
    echo "<colgroup>";
    for ($i = 0; $i < $num_rows; $i++) {
        echo "<col style=\"width: auto;\">";
    }
    echo "</colgroup>";
    echo "<tbody>";
    for ($i = 0; $i <= $num_rows; $i++) {
        echo "<tr>";
        for ($j = 0; $j <= $num_rows; $j++) {
            if  ($j == 0) {
                echo "<td>". $i. "</td>";
            } else if ($i == 0) {
                echo "<td>". $j. "</td>";
            } else {
                echo "<td>". $i*$j. "</td>";
            }
            
        }
        echo "</tr>";
    }
    echo "</tbody>";
    echo "</table>";
} 
?>

</html>