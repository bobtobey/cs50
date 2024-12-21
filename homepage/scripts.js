// Universal Event Listener
document.addEventListener('DOMContentLoaded', function() {
    // initialize varibles for dialog and dialog buttons
    const toggleButton = document.querySelector("#open-article-image-bloc1");
    const dialogBloc = document.querySelector("#article-image-bloc1");
    const closeButton = document.querySelector("#article-image-bloc1 .btn-primary");

    // Toggle Dialog Display
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
