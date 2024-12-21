// Universal Event Listener
document.addEventListener('DOMContentLoaded', function() {
    // Select the buttons and the dialog using querySelector
    const toggleButton = document.querySelector("#open-article-image-bloc1");
    const dialogBloc = document.querySelector("#article-image-bloc1");
    const closeButton = document.querySelector("#article-image-bloc1 .btn-primary");

    // Function to toggle visibility
    function toggleDialog() {
        if (dialogBloc.style.display === "none" || dialogBloc.style.display === "") {
            dialogBloc.style.display = "block";
        } else {
            dialogBloc.style.display = "none";
        }
    }

    // Event listener for the open button
    toggleButton.addEventListener("click", toggleDialog);

    // Event listener for the close button
    closeButton.addEventListener("click", toggleDialog);
});
