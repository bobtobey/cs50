

// Toggle Dialog Display
function dialogToggle(dialog, dialogCaller) {
    // Get current display state
    const currentState = window.getComputedStyle(dialog).display;

    if (currentState === 'none') {
        // Store the original border color if not already stored
        if (!dialog.dataset.originalBorderColor) {
            dialog.dataset.originalBorderColor = window.getComputedStyle(dialog).borderColor;
        }

        dialog.style.display = 'block';
        dialog.setAttribute('data-dialog-state', 'true');
        dialogCaller.classList.remove('btn-target-off');
        dialogCaller.classList.add('btn-target-on');
    } else {
        dialog.style.display = 'none';
        dialog.setAttribute('data-dialog-state', 'false');
        dialog.style.borderColor = dialog.dataset.originalBorderColor; // Reset to original border color when closing
        dialogCaller.classList.remove('btn-target-on');
        dialogCaller.classList.add('btn-target-off');
    }
}
// Universal Event Listener
document.addEventListener('DOMContentLoaded', function() {
    // Document listeners
    document.body.addEventListener('click', function(event) {
        const evntTarget= event.target;
        // console.log("Clicked element:", evntTarget);

        if(evntTarget.closest('[data-dialog-toggle="true"]')) {
            event.preventDefault();
            dialogInitializer(event, {
                alert: false,
                update: false
            });
        };

        // Close dialog with button
        if(evntTarget.closest('.btn-close')) {
            const btnClose = evntTarget.closest('.portfolio-assets-bloc');
            if(btnClose) {
                dialogToggle(btnClose);
            }
        }
    })
});
