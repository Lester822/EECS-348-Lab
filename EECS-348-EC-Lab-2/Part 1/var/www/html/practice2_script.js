function updateColor() {

    const redColor = document.getElementById('redColor').value;
    const blueColor = document.getElementById('blueColor').value;
    const greenColor = document.getElementById('greenColor').value;

    const color_text = document.getElementById('colorchangetext');

    color_text.style.color = "rgb(" + redColor + "," + greenColor + "," + blueColor + ")";

}

function updateBorder() {

    const redColor = document.getElementById('BredColor').value;
    const blueColor = document.getElementById('BblueColor').value;
    const greenColor = document.getElementById('BgreenColor').value;

    const color_text = document.getElementById('colorchangetext');

    color_text.style.borderStyle = "solid";
    color_text.style.borderColor = "rgb(" + redColor + "," + greenColor + "," + blueColor + ")";
    
}

function updateBorderWidth() {

    const borderWidth = document.getElementById('borderPixels').value;

    const color_text = document.getElementById('colorchangetext');

    color_text.style.borderStyle = "solid";
    color_text.style.borderWidth = borderWidth + "px";



}
