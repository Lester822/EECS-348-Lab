function log_in() {

    document.getElementById("verification").innerHTML = "";
    const first_password = document.getElementById("first_password").value;
    const confirm_password = document.getElementById("confirm_password").value;

    if (first_password.length < 8) {
        window.alert("Password Invalid: Too Few Characters")
    } else if (first_password != confirm_password) {
        window.alert("Passwords do not match.")
    } else {
        document.getElementById("verification").innerHTML = "Password Success";
    }
    
}
