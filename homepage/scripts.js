
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
